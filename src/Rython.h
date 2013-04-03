#include "RcppExtension.h"
#include "PythonInterface.h"

RcppExport SEXP Rython__initialize();
  
RcppExport SEXP Rython__finalize();  

RcppExport SEXP Rython__run(SEXP Rpy_script);

RcppExport SEXP Rython__fun(SEXP Rpymodule_name, SEXP Rpyfun_name, SEXP Rpyfun_argv);

RcppExport SEXP Rython__assign(SEXP Rpy_ptr, SEXP Rname, SEXP Rmodule_name);