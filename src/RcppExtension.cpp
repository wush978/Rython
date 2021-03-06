#include <vector>
#include <string>

#include "RcppExtension.h"

namespace py = boost::python;

using Rcpp::CharacterVector;
using Rcpp::List;

typedef std::vector<std::string> StrVec;

namespace Rython {
  
	py::list as(const CharacterVector& src) {
    std::string glue;
		py::list retval;
		for(int i = 0;i < src.size();i++) {
      glue.assign(CHAR(STRING_ELT(wrap(src), i)));
			retval.append(glue);
		}
		return retval;
	}

  py::list as(const List& src) {
    py::list retval;
    
    for(int i = 0;i < src.size();i++) {
      CharacterVector element(VECTOR_ELT(wrap(src), i));
      retval.append(as(element));
    }
    return(retval);
  }
  
	SEXP wrap(py::list& src) {
    std::vector< std::string > glue;
		for(int i = 0;i < py::len(src);i++) {
			glue.push_back(py::extract<std::string>(src[i]));
		}
		return Rcpp::wrap(glue);
	}

}
