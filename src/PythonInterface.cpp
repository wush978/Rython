#include <dlfcn.h>
#include <Python.h>
#include "PythonInterface.h"

namespace Rython {
  void Py_initialize() {
    ::Py_SetProgramName("Rython");
    ::dlopen("libpython2.7.so", RTLD_LAZY | RTLD_GLOBAL);
    ::Py_Initialize();
  }
  
  void Py_finalize() {
    ::Py_Finalize();
  }
  
  void Py_run(const char* script) {
    ::PyRun_SimpleString(script);
  }
}