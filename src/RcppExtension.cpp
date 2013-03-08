#include <vector>
#include <string>

#include "RcppExtension.h"

namespace py = boost::python;

using Rcpp::CharacterVector;

typedef std::vector<std::string> StrVec;

namespace Rython {

	py::list as(const CharacterVector& src) {
    std::string glue;
		py::list retval;
		for(int i = 0;i < src.size();i++) {
      
			retval.append(glue[i]);
		}
		return retval;
	}

	SEXP wrap(py::list& src) {
    CharacterVector retval;
		for(int i = 0;i < py::len(src);i++) {
			retval.push_back(py::extract<std::string>(src[i]));
		}
		return retval;
	}

}
