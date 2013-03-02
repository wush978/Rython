#include "Rython.h"

SEXP Rython__initialize() {
  BEGIN_RCPP
  Rython::Py_initialize();
  Rcpp::Rcout << "Initializing Python Interpreter..." << std::endl;
  return R_NilValue;
  END_RCPP
}

SEXP Rython__finalize() {
  BEGIN_RCPP
  Rython::Py_finalize();
  Rcpp::Rcout << "Finalizing Python Interpreter..." << std::endl;
  return R_NilValue;
  END_RCPP
}

SEXP Rython__run(SEXP Rpy_script) {
  BEGIN_RCPP
  std::string py_script(Rcpp::as<std::string>(Rpy_script));
  Rython::Py_run(py_script.c_str());
  END_RCPP
}