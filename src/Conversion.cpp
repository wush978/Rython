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
        py::object temp(py::extract<py::object>(src[i]));
        
      }
      return retval;
    }
  }
  catch (py::error_already_set) {
  	PyErr_Print();
	}
  END_RCPP
}