// redirect python stdout to R stdout

#include "PythonInterface.h"
#include <Rcpp.h>

static PyObject* redirection_stdoutredirect(PyObject* self, PyObject *args) {
  const char* string;
  if (!PyArg_ParseTuple(args, "s", &string))
    return NULL;
  Rcpp::Rcout << string;
  Py_INCREF(Py_None);
  return Py_None;
}

PyMethodDef RedirectionMethods[] = {
  {"stdoutredirect", redirection_stdoutredirect, METH_VARARGS, 
    "stdout redirection helper"},
  {NULL, NULL, 0, NULL}
};

