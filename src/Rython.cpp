#include "Rython.h"

namespace py = boost::python;

SEXP Rython__initialize() {
	BEGIN_RCPP
	Rython_initialize();
	Rcpp::Rcout << "Initializing Python Interpreter..." << std::endl;
	return R_NilValue;
	END_RCPP
}

SEXP Rython__finalize() {
	BEGIN_RCPP
	Rython_finalize();
	Rcpp::Rcout << "Finalizing Python Interpreter..." << std::endl;
	return R_NilValue;
	END_RCPP
}

SEXP Rython__run(SEXP Rpy_script) {
	BEGIN_RCPP
	std::string py_script(Rcpp::as<std::string>(Rpy_script));
	::PyRun_SimpleString(py_script.c_str());
	END_RCPP
}

SEXP Rython__fun(SEXP Rpymodule_name, SEXP Rpyfun_name, SEXP Rpyfun_argv) {
	BEGIN_RCPP

	try {
		const char
			*pymodule_name = ::CHAR(::STRING_ELT(Rpymodule_name, 0)),
			*pyfun_name = ::CHAR(::STRING_ELT(Rpyfun_name, 0));
		py::object module((py::handle<>(py::borrowed(PyImport_AddModule(pymodule_name)))));
		py::object pyfun = module.attr("__dict__")[pyfun_name];
		if (!pyfun.ptr()) {
			throw std::invalid_argument("pyfun_name not found in python");
		}
		if (!PyCallable_Check(pyfun.ptr())) {
			throw std::invalid_argument("pyfun_name is not a callable");
		}
    if (Rf_isString(Rpyfun_argv)) {
      Rcpp::CharacterVector pyfun_argv(Rpyfun_argv);
  		py::list argv(Rython::as(pyfun_argv));
  		py::list result(pyfun(argv));
  		return Rython::wrap(result);
    }
    if (Rf_isVector(Rpyfun_argv)) {
      Rcpp::List pyfun_argv(Rpyfun_argv);
    	py::list argv(Rython::as(pyfun_argv));
  		py::list result(pyfun(argv));
  		return Rython::wrap(result);
    }
	}
	catch (py::error_already_set) {
		PyErr_Print();
	}

	END_RCPP
}
