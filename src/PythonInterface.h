
#ifndef __PYTHONINTERFACE_H__
#define __PYTHONINTERFACE_H__

#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

void Rython_initialize(void);
void Rython_finalize(void);
static PyObject* redirection_stdoutredirect(PyObject* self, PyObject *args);
extern PyMethodDef RedirectionMethods[];

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__PYTHONINTERFACE_H__
