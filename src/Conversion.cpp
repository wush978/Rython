#include <map>
#include "Conversion.h"
#include <boost/python/raw_function.hpp>

namespace py = boost::python;

typedef Rcpp::XPtr<py::list> PyList;
typedef Rcpp::XPtr<py::object> PyObj;

template<class T_in, class T_glue> 
PyList Rython__as(SEXP Rsrc) {
  PyList retval(new py::list);
  T_in src(Rsrc);
  T_glue glue;
  for(int i = 0;i < src.size();i++) {
    glue = src[i];
    retval->append(glue);
  }
  return retval;
}

SEXP Rython__pylong(SEXP Rsrc) {
  BEGIN_RCPP
  return Rcpp::wrap<PyList>(Rython__as<Rcpp::IntegerVector, long>(Rsrc));
  END_RCPP
}

SEXP Rython__pyfloat(SEXP Rsrc) {
	BEGIN_RCPP
  return Rcpp::wrap<PyList>(Rython__as<Rcpp::NumericVector, double>(Rsrc));
	END_RCPP
}

SEXP Rython__pybool(SEXP Rsrc) {
	BEGIN_RCPP
  return Rcpp::wrap<PyList>(Rython__as<Rcpp::LogicalVector, bool>(Rsrc));
	END_RCPP
}

SEXP Rython__pystr(SEXP Rsrc) {
	BEGIN_RCPP
  return Rcpp::wrap<PyList>(Rython__as<Rcpp::CharacterVector, std::string>(Rsrc));
	END_RCPP
}

SEXP Rython__retrieve_pyobj(SEXP Rmodule_name, SEXP Robj_name) {
  BEGIN_RCPP
  try {
  	std::string 
      pymodule_name(Rcpp::as<std::string>(Rmodule_name)),
  		obj_name(Rcpp::as<std::string>(Robj_name));
    std::auto_ptr<py::object> pmodule;
    if (pymodule_name.size() > 0) {
      pmodule.reset(new py::object((py::handle<>(py::borrowed(PyImport_AddModule(pymodule_name.c_str()))))));
    } 
    else {
      pmodule.reset(new py::object(py::handle<>(py::borrowed(PyImport_AddModule("__main__")))));
    }
    py::object dictionary = pmodule->attr("__dict__");
    PyObj retval(new py::object(dictionary[obj_name.c_str()]));
    return retval;
  }
	catch (py::error_already_set) {
		PyErr_Print();
	}
  END_RCPP
}

SEXP Rython__call(SEXP Rpy_callable, SEXP Rargv) {
  BEGIN_RCPP
  
  try {
    PyObj py_callable(Rpy_callable);
    Rcpp::List argv(Rargv);
    py::list args;
    for(int i = 0;i < argv.size();i++) {
      PyList argv_element(Rcpp::wrap(argv[i]));
      args.append(*argv_element);
    }
    PyObj retval(new py::object((*py_callable)(*boost::python::tuple(args))));
    return retval;
  }
  catch (py::error_already_set) {
		PyErr_Print();
	}
   
  END_RCPP
}

RcppExport SEXP Rython__wrap(SEXP Rsrc, SEXP Ris_list) {
  BEGIN_RCPP
  try {
    bool is_list(Rcpp::as<bool>(Ris_list));
    py::list& src(*PyList(Rsrc));
    int n = py::len(*src);
    if (n == 0) return R_NilValue;
    if (is_list) {
      Rcpp::List retval(n);
      for(int i = 0;i < n;i++) {
        py::object temp = py::extract<py::object>(src[i]);
        if (PyString_Check(temp.ptr())) {
          retval[i] = Rcpp::wrap<std::string>(py::extract<std::string>(src[i]));
        }
        else if (temp.ptr() == Py_None) {
          retval[i] = R_NilValue;
        }
        else if (PyBool_Check(temp.ptr())) {
          retval[i] = Rcpp::wrap<bool>(py::extract<bool>(src[i]));
        }
        else if (PyInt_Check(temp.ptr()) || PyLong_Check(temp.ptr())) {
          retval[i] = Rcpp::wrap<long>(py::extract<long>(src[i]));
        }
        else if (PyFloat_Check(temp.ptr())) {
          retval[i] = Rcpp::wrap<double>(py::extract<double>(src[i]));
        }
        else if (PyUnicode_Check(temp.ptr())) {
          retval[i] = Rcpp::wrap<std::wstring>(py::extract<std::wstring>(src[i]));
        }
      } // for
      return retval;
    }
    else { // is_list
      int j = 0;
      py::object first_element = py::extract<py::object>(src[j]);
      if (PyString_Check(first_element.ptr())) {
        std::vector<std::string> retval;
        retval.reserve(n);
        for(int i = 0;i < n;i++) {
          retval.push_back(py::extract<std::string>(src[i]));
        }
        return Rcpp::wrap(retval);
      }
      else if (first_element.ptr() == Py_None) {
        return R_NilValue;
      }
      else if (PyBool_Check(first_element.ptr())) {
        Rcpp::LogicalVector retval(n);
        for(int i = 0;i < n;i++) {
          retval[i] = py::extract<bool>(src[i]);
        }
        return retval;
      }
      else if (PyInt_Check(first_element.ptr()) || PyLong_Check(first_element.ptr())) {
        Rcpp::IntegerVector retval(n);
        for(int i = 0;i < n;i++) {
          retval[i] = py::extract<long>(src[i]);
        }
        return retval;
      }
      else if (PyFloat_Check(first_element.ptr())) {
        Rcpp::NumericVector retval(n);
        for(int i = 0;i < n;i++) {
          retval[i] = py::extract<double>(src[i]);
        }
        return retval;
      }
      else if (PyUnicode_Check(first_element.ptr())) {
        std::vector< std::wstring > retval;
        retval.resize(n);
        for(int i = 0;i < n;i++) {
          retval.push_back(py::extract<std::wstring>(src[i]));
        }
        return Rcpp::wrap<std::vector<std::wstring> >(retval);
      }
    }
  }
  catch (py::error_already_set) {
  	PyErr_Print();
	}
  END_RCPP
}