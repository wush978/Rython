#ifndef __CONVERSION_H__ 
#define __CONVERSION_H__

#include <boost/python.hpp>

#include <Rcpp.h>

RcppExport SEXP Rython__pylong(SEXP Rsrc);
RcppExport SEXP Rython__pyfloat(SEXP Rscr);
RcppExport SEXP Rython__pybool(SEXP Rscr);
RcppExport SEXP Rython__pystr(SEXP Rscr);
RcppExport SEXP Rython__retrieve_pyobj(SEXP Rmodule_name, SEXP Rfun_name);
RcppExport SEXP Rython__call(SEXP Rpy_callable, SEXP Rargv);

#endif //__CONVERSION_H__