#ifndef __H_RCPPEXTENSION__
#define __H_RCPPEXTENSION__

#include <RcppCommon.h>

#include <boost/python.hpp>
namespace Rcpp {
  template <> SEXP wrap(const boost::python::list&);
  template <> boost::python::list as( SEXP );
}

#include <Rcpp.h>

#endif //__H_RCPPEXTENSION__