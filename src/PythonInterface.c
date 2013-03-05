#include <dlfcn.h>
#include "PythonInterface.h"

void Rython_initialize(void) {
  Py_SetProgramName("Rython");
  dlopen("libpython2.7.so", RTLD_LAZY | RTLD_GLOBAL);
  Py_Initialize();
}
  
void Rython_finalize(void) {
  Py_Finalize();
}
