#ifndef __H_RCPPEXTENSION__
#define __H_RCPPEXTENSION__

#include <boost/python.hpp>

#include <Rcpp.h>

namespace Rython {

	boost::python::list as(const Rcpp::CharacterVector& src);

	SEXP wrap(boost::python::list&);

}

#endif //__H_RCPPEXTENSION__
