#include "RcppExtension.h"
#include "PythonInterface.h"

RcppExport SEXP Rython__initialize();
  
RcppExport SEXP Rython__finalize();  

RcppExport SEXP Rython__run(SEXP Rpy_script);

RcppExport SEXP Rython__call(SEXP Rpymodule_name, SEXP Rpyfun_name, SEXP Rpyfun_argv);

