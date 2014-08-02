// sudo apt-get install python-dev
//gcc -shared -I/usr/include/python2.7/ -lpython2.7 -o rs232_Module.so rs232_Module.c rs232_comm.c rs232.c

#include <Python.h>
#include "stdbool.h"

/*
 * Another function to be called from Python
 */
static PyObject* py_power_up(PyObject* self, PyObject* args)
{
  char message[100];
	int window_id, porcentaje_apertura, return_value, is_persiana;
	PyArg_ParseTuple(args, "iii", &window_id, &porcentaje_apertura, &is_persiana);
  return_value = power_up(window_id, porcentaje_apertura, is_persiana);
  if (return_value == -1)
     memcpy(message, "Opened correctly", sizeof("Opened correctly"));
  else
     memcpy(message, "Opened fail", sizeof("Opened fail"));

	return Py_BuildValue("s", message);
}

/*
 * Another function to be called from Python
 */
static PyObject* py_power_down(PyObject* self, PyObject* args)
{
  char message[100];
	int window_id, porcentaje_apertura, return_value, is_persiana;
	PyArg_ParseTuple(args, "iii", &window_id, &porcentaje_apertura, &is_persiana);
  return_value = power_down(window_id, porcentaje_apertura, is_persiana);
  if (return_value == -1)
     memcpy(message, "Closed correctly", sizeof("Closed correctly"));
  else
     memcpy(message, "Closed fail", sizeof("Closed fail"));

	return Py_BuildValue("s", message);
}
/*
 * Bind Python function names to our C functions
 */
static PyMethodDef myModule_methods[] = {
	{"myPowerUP", py_power_up, METH_VARARGS, NULL},
	{"myPowerDown", py_power_down, METH_VARARGS, NULL},
	{NULL, NULL, 0, NULL}
};

/*
 * Python calls this to let us initialize our module
 */
void initrs232_Module()
{
	(void) Py_InitModule("rs232_Module", myModule_methods);
}
