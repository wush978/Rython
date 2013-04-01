#include "conversion.h"

namespace py = boost::python;

template<class T_in, class T_glue> 
Rcpp::XPtr<py::list> Rython__as(SEXP Rsrc) {
  Rcpp::XPtr<py::list> retval(new py::list);
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
  return Rcpp::wrap<Rcpp::XPtr<py::list> >(Rython__as<Rcpp::IntegerVector, long>(Rsrc));
  END_RCPP
}


RcppExport SEXP Rython__pyfloat(SEXP Rsrc) {
	BEGIN_RCPP
  return Rcpp::wrap<Rcpp::XPtr<py::list> >(Rython__as<Rcpp::NumericVector, double>(Rsrc));
	END_RCPP
}
RcppExport SEXP Rython__pybool(SEXP Rsrc) {
	BEGIN_RCPP
  return Rcpp::wrap<Rcpp::XPtr<py::list> >(Rython__as<Rcpp::LogicalVector, bool>(Rsrc));
	END_RCPP
}
RcppExport SEXP Rython__pystr(SEXP Rsrc) {
	BEGIN_RCPP
  return Rcpp::wrap<Rcpp::XPtr<py::list> >(Rython__as<Rcpp::CharacterVector, std::string>(Rsrc));
	END_RCPP
}
