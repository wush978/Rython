#include "RcppExtension.h"
#include "PythonInterface.h"

RcppExport SEXP Rython__initialize();
  
RcppExport SEXP Rython__finalize();  

RcppExport SEXP Rython__run(SEXP Rpy_script);