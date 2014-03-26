/**
 * @author Andre Anjos <andre.anjos@idiap.ch>
 * @date Tue 14 Jan 2014 14:26:09 CET
 *
 * @brief Bindings for a Bob compatible LIBSVM-based Machine for SVMs
 *
 * Copyright (C) 2011-2013 Idiap Research Institute, Martigny, Switzerland
 */

#define XBOB_LEARN_LIBSVM_MODULE
#include <xbob.blitz/cppapi.h>
#include <xbob.blitz/cleanup.h>
#include <xbob.io/api.h>
#include <xbob.learn.libsvm/api.h>
#include <structmember.h>

/************************************************
 * Implementation of xbob.learn.libsvm.svm_type *
 ************************************************/

PyDoc_STRVAR(s_svm_type_str, XBOB_EXT_MODULE_PREFIX ".svm_type");

PyDoc_STRVAR(s_svm_type_doc,
"svm_type (C++ enumeration) - cannot be instantiated from Python\n\
\n\
Available values are:\n\
\n\
  * C_SVC\n\
  * NU_SVC\n\
  * ONE_CLASS\n\
  * EPSILON_SVR\n\
  * NU_SVR\n\
\n\
A dictionary containing all names and values available for this\n\
enumeration is available through the attribute ``entries``.\n\
"
);

static int insert_item_string(PyObject* dict, PyObject* entries,
    const char* key, Py_ssize_t value) {
  auto v = make_safe(Py_BuildValue("n", value));
  if (PyDict_SetItemString(dict, key, v.get()) < 0) return -1;
  return PyDict_SetItemString(entries, key, v.get());
}

static PyObject* create_svm_type_enumerations() {
  auto retval = PyDict_New();
  if (!retval) return 0;
  auto retval_ = make_safe(retval);

  auto entries = PyDict_New();
  if (!entries) return 0;
  auto entries_ = make_safe(entries);

  if (insert_item_string(retval, entries, "C_SVC",
        bob::learn::libsvm::Machine::C_SVC) < 0) return 0;
  if (insert_item_string(retval, entries, "NU_SVC",
        bob::learn::libsvm::Machine::NU_SVC) < 0) return 0;
  if (insert_item_string(retval, entries, "ONE_CLASS",
        bob::learn::libsvm::Machine::ONE_CLASS) < 0) return 0;
  if (insert_item_string(retval, entries, "EPSILON_SVR",
        bob::learn::libsvm::Machine::EPSILON_SVR) < 0) return 0;
  if (insert_item_string(retval, entries, "NU_SVR",
        bob::learn::libsvm::Machine::NU_SVR) < 0) return 0;

  if (PyDict_SetItemString(retval, "entries", entries) < 0) return 0;

  Py_INCREF(retval);
  return retval;
}

static int PyBobLearnLibsvmMachineSvmType_Init(PyObject* self, PyObject*, PyObject*) {

  PyErr_Format(PyExc_NotImplementedError, "cannot initialize C++ enumeration bindings `%s' - use one of the class' attached attributes instead", Py_TYPE(self)->tp_name);
  return -1;

}

PyTypeObject PyBobLearnLibsvmMachineSvmType_Type = {
    PyVarObject_HEAD_INIT(0, 0)
    s_svm_type_str,                               /* tp_name */
    sizeof(PyBobLearnLibsvmMachineSvmType_Type),  /* tp_basicsize */
    0,                                            /* tp_itemsize */
    0,                                            /* tp_dealloc */
    0,                                            /* tp_print */
    0,                                            /* tp_getattr */
    0,                                            /* tp_setattr */
    0,                                            /* tp_compare */
    0,                                            /* tp_repr */
    0,                                            /* tp_as_number */
    0,                                            /* tp_as_sequence */
    0,                                            /* tp_as_mapping */
    0,                                            /* tp_hash */
    0,                                            /* tp_call */
    0,                                            /* tp_str*/
    0,                                            /* tp_getattro*/
    0,                                            /* tp_setattro*/
    0,                                            /* tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,     /* tp_flags*/
    s_svm_type_doc,                               /* tp_doc */
    0,		                                        /* tp_traverse */
    0,		                                        /* tp_clear */
    0,                                            /* tp_richcompare */
    0,		                                        /* tp_weaklistoffset */
    0,		                                        /* tp_iter */
    0,		                                        /* tp_iternext */
    0,                                            /* tp_methods */
    0,                                            /* tp_members */
    0,                                            /* tp_getset */
    0,                                            /* tp_base */
    create_svm_type_enumerations(),               /* tp_dict */
    0,                                            /* tp_descr_get */
    0,                                            /* tp_descr_set */
    0,                                            /* tp_dictoffset */
    PyBobLearnLibsvmMachineSvmType_Init,          /* tp_init */
    0,                                            /* tp_alloc */
    0,                                            /* tp_new */
};

/*******************************************************
 * Implementation of xbob.learn.libsvm.svm_kernel_type *
 *******************************************************/

PyDoc_STRVAR(s_svm_kernel_type_str, XBOB_EXT_MODULE_PREFIX ".svm_kernel_type");

PyDoc_STRVAR(s_svm_kernel_type_doc,
"svm_kernel_type (C++ enumeration) - cannot be instantiated from Python\n\
\n\
Available values are:\n\
\n\
  * LINEAR\n\
  * POLY\n\
  * RBF\n\
  * SIGMOID\n\
  * PRECOMPUTED\n\
\n\
A dictionary containing all names and values available for this\n\
enumeration is available through the attribute ``entries``.\n\
"
);

static PyObject* create_svm_kernel_type_enumerations() {
  auto retval = PyDict_New();
  if (!retval) return 0;
  auto retval_ = make_safe(retval);

  auto entries = PyDict_New();
  if (!entries) return 0;
  auto entries_ = make_safe(entries);

  if (insert_item_string(retval, entries, "LINEAR",
        bob::learn::libsvm::Machine::C_SVC) < 0) return 0;
  if (insert_item_string(retval, entries, "POLY",
        bob::learn::libsvm::Machine::NU_SVC) < 0) return 0;
  if (insert_item_string(retval, entries, "RBF",
        bob::learn::libsvm::Machine::ONE_CLASS) < 0) return 0;
  if (insert_item_string(retval, entries, "SIGMOID",
        bob::learn::libsvm::Machine::EPSILON_SVR) < 0) return 0;
  if (insert_item_string(retval, entries, "PRECOMPUTED",
        bob::learn::libsvm::Machine::NU_SVR) < 0) return 0;

  if (PyDict_SetItemString(retval, "entries", entries) < 0) return 0;

  Py_INCREF(retval);
  return retval;
}

static int PyBobLearnLibsvmMachineSvmKernelType_Init(PyObject* self, PyObject*, PyObject*) {

  PyErr_Format(PyExc_NotImplementedError, "cannot initialize C++ enumeration bindings `%s' - use one of the class' attached attributes instead", Py_TYPE(self)->tp_name);
  return -1;

}

PyTypeObject PyBobLearnLibsvmMachineSvmKernelType_Type = {
    PyVarObject_HEAD_INIT(0, 0)
    s_svm_kernel_type_str,                              /* tp_name */
    sizeof(PyBobLearnLibsvmMachineSvmKernelType_Type),  /* tp_basicsize */
    0,                                                  /* tp_itemsize */
    0,                                                  /* tp_dealloc */
    0,                                                  /* tp_print */
    0,                                                  /* tp_getattr */
    0,                                                  /* tp_setattr */
    0,                                                  /* tp_compare */
    0,                                                  /* tp_repr */
    0,                                                  /* tp_as_number */
    0,                                                  /* tp_as_sequence */
    0,                                                  /* tp_as_mapping */
    0,                                                  /* tp_hash */
    0,                                                  /* tp_call */
    0,                                                  /* tp_str*/
    0,                                                  /* tp_getattro*/
    0,                                                  /* tp_setattro*/
    0,                                                  /* tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,           /* tp_flags*/
    s_svm_kernel_type_doc,                              /* tp_doc */
    0,		                                              /* tp_traverse */
    0,		                                              /* tp_clear */
    0,                                                  /* tp_richcompare */
    0,		                                              /* tp_weaklistoffset */
    0,		                                              /* tp_iter */
    0,		                                              /* tp_iternext */
    0,                                                  /* tp_methods */
    0,                                                  /* tp_members */
    0,                                                  /* tp_getset */
    0,                                                  /* tp_base */
    create_svm_kernel_type_enumerations(),              /* tp_dict */
    0,                                                  /* tp_descr_get */
    0,                                                  /* tp_descr_set */
    0,                                                  /* tp_dictoffset */
    PyBobLearnLibsvmMachineSvmKernelType_Init,          /* tp_init */
    0,                                                  /* tp_alloc */
    0,                                                  /* tp_new */
};

/*******************************************************
 * Implementation of Support Vector Machine base class *
 *******************************************************/

PyDoc_STRVAR(s_svm_str, XBOB_EXT_MODULE_PREFIX ".Machine");

PyDoc_STRVAR(s_svm_doc,
"Machine(path)\n\
\n\
Machine(hdf5file)\n\
\n\
This class can load and run an SVM generated by libsvm.\n\
Libsvm is a simple, easy-to-use, and efficient software\n\
for SVM classification and regression. It solves C-SVM\n\
classification, nu-SVM classification, one-class-SVM,\n\
epsilon-SVM regression, and nu-SVM regression. It also provides\n\
an automatic model selection tool for C-SVM classification.\n\
More information about libsvm can be found on its `website\n\
<http://www.csie.ntu.edu.tw/~cjlin/libsvm/>`_. In particular,\n\
this class covers most of the functionality provided by the\n\
command-line utility svm-predict.\n\
\n\
Input and output is always performed on 1D or 2D arrays with\n\
64-bit floating point numbers.\n\
\n\
This machine can be initialized in two ways: the first is using\n\
an original SVM text file as produced by ``libsvm``. The\n\
second option is to pass a pre-opened HDF5 file pointing to the\n\
machine information to be loaded in memory.\n\
\n\
Using the first constructor, we build a new machine from a\n\
libsvm model file. When you load using the libsvm model loader,\n\
note that the scaling parameters will be set to defaults\n\
(subtraction of 0.0 and division by 1.0). If you need scaling\n\
to be applied, set it individually using the appropriate methods\n\
on the returned object.\n\
\n\
Using the second constructor, we build a new machine from an\n\
HDF5 file containing not only the machine support vectors, but\n\
also the scaling factors. Using this constructor assures a 100%\n\
state recovery from previous sessions.\n\
\n\
");

/***********************************************
 * Implementation of xbob.learn.libsvm.Machine *
 ***********************************************/

static int PyBobLearnLibsvmMachine_init_svmfile
(PyBobLearnLibsvmMachineObject* self, PyObject* args, PyObject* kwds) {

  /* Parses input arguments in a single shot */
  static const char* const_kwlist[] = {"filename", 0};
  static char** kwlist = const_cast<char**>(const_kwlist);

  PyObject* filename = 0;

  if (!PyArg_ParseTupleAndKeywords(args, kwds, "O&", kwlist,
        &PyBobIo_FilenameConverter, &filename))
    return -1;

  auto filename_ = make_safe(filename);

#if PY_VERSION_HEX >= 0x03000000
  const char* c_filename = PyBytes_AS_STRING(filename);
#else
  const char* c_filename = PyString_AS_STRING(filename);
#endif

  try {
    self->cxx = new bob::learn::libsvm::Machine(c_filename);
  }
  catch (std::exception& ex) {
    PyErr_SetString(PyExc_RuntimeError, ex.what());
    return -1;
  }
  catch (...) {
    PyErr_Format(PyExc_RuntimeError, "cannot create new object of type `%s' - unknown exception thrown", Py_TYPE(self)->tp_name);
    return -1;
  }

  return 0;

}

static int PyBobLearnLibsvmMachine_init_hdf5
(PyBobLearnLibsvmMachineObject* self, PyObject* args, PyObject* kwds) {

  /* Parses input arguments in a single shot */
  static const char* const_kwlist[] = {"config", 0};
  static char** kwlist = const_cast<char**>(const_kwlist);

  PyObject* config = 0;

  if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!", kwlist,
        &PyBobIoHDF5File_Type, &config)) return -1;

  auto h5f = reinterpret_cast<PyBobIoHDF5FileObject*>(config);

  try {
    self->cxx = new bob::learn::libsvm::Machine(*(h5f->f));
  }
  catch (std::exception& ex) {
    PyErr_SetString(PyExc_RuntimeError, ex.what());
    return -1;
  }
  catch (...) {
    PyErr_Format(PyExc_RuntimeError, "cannot create new object of type `%s' - unknown exception thrown", Py_TYPE(self)->tp_name);
    return -1;
  }

  return 0;

}

static int PyBobLearnLibsvmMachine_init(PyBobLearnLibsvmMachineObject* self,
    PyObject* args, PyObject* kwds) {

  Py_ssize_t nargs = (args?PyTuple_Size(args):0) + (kwds?PyDict_Size(kwds):0);

  if (nargs != 1) {
    PyErr_Format(PyExc_RuntimeError, "number of arguments mismatch - %s requires 1 arguments, but you provided %" PY_FORMAT_SIZE_T "d (see help)", Py_TYPE(self)->tp_name, nargs);
    return -1;
  }

  PyObject* arg = 0; ///< borrowed (don't delete)
  if (PyTuple_Size(args)) arg = PyTuple_GET_ITEM(args, 0);
  else {
    PyObject* tmp = PyDict_Values(kwds);
    auto tmp_ = make_safe(tmp);
    arg = PyList_GET_ITEM(tmp, 0);
  }

  if (PyBobIoHDF5File_Check(arg)) {
    return PyBobLearnLibsvmMachine_init_hdf5(self, args, kwds);
  }
  else {
    return PyBobLearnLibsvmMachine_init_svmfile(self, args, kwds);
  }

}

static void PyBobLearnLibsvmMachine_delete
(PyBobLearnLibsvmMachineObject* self) {

  delete self->cxx;
  Py_TYPE(self)->tp_free((PyObject*)self);

}

int PyBobLearnLibsvmMachine_Check(PyObject* o) {
  return PyObject_IsInstance(o, reinterpret_cast<PyObject*>(&PyBobLearnLibsvmMachine_Type));
}

PyDoc_STRVAR(s_input_subtract_str, "input_subtract");
PyDoc_STRVAR(s_input_subtract_doc,
"Input subtraction factor, before feeding data through the\n\
weight matrix W. The subtraction is the first applied\n\
operation in the processing chain - by default, it is set to\n\
0.0.\n\
");

static PyObject* PyBobLearnLibsvmMachine_getInputSubtraction
(PyBobLearnLibsvmMachineObject* self, void* /*closure*/) {
  return PyBlitzArray_NUMPY_WRAP(PyBlitzArrayCxx_NewFromConstArray(self->cxx->getInputSubtraction()));
}

static int PyBobLearnLibsvmMachine_setInputSubtraction
(PyBobLearnLibsvmMachineObject* self, PyObject* o, void* /*closure*/) {

  PyBlitzArrayObject* input_subtract = 0;
  if (!PyBlitzArray_Converter(o, &input_subtract)) return -1;
  auto input_subtract_ = make_safe(input_subtract);

  if (input_subtract->type_num != NPY_FLOAT64 || input_subtract->ndim != 1) {
    PyErr_Format(PyExc_TypeError, "`%s' only supports 64-bit floats 1D arrays for property array `input_subtract'", Py_TYPE(self)->tp_name);
    return -1;
  }

  try {
    self->cxx->setInputSubtraction(*PyBlitzArrayCxx_AsBlitz<double,1>(input_subtract));
  }
  catch (std::exception& ex) {
    PyErr_SetString(PyExc_RuntimeError, ex.what());
    return -1;
  }
  catch (...) {
    PyErr_Format(PyExc_RuntimeError, "cannot reset `input_subtract' of %s: unknown exception caught", Py_TYPE(self)->tp_name);
    return -1;
  }

  return 0;

}

PyDoc_STRVAR(s_input_divide_str, "input_divide");
PyDoc_STRVAR(s_input_divide_doc,
"Input division factor, before feeding data through the\n\
weight matrix W. The division is applied just after\n\
subtraction - by default, it is set to 1.0.\n\
");

static PyObject* PyBobLearnLibsvmMachine_getInputDivision
(PyBobLearnLibsvmMachineObject* self, void* /*closure*/) {
  return PyBlitzArray_NUMPY_WRAP(PyBlitzArrayCxx_NewFromConstArray(self->cxx->getInputDivision()));
}

static int PyBobLearnLibsvmMachine_setInputDivision
(PyBobLearnLibsvmMachineObject* self, PyObject* o, void* /*closure*/) {

  PyBlitzArrayObject* input_divide = 0;
  if (!PyBlitzArray_Converter(o, &input_divide)) return -1;
  auto input_divide_ = make_safe(input_divide);

  if (input_divide->type_num != NPY_FLOAT64 || input_divide->ndim != 1) {
    PyErr_Format(PyExc_TypeError, "`%s' only supports 64-bit floats 1D arrays for property array `input_divide'", Py_TYPE(self)->tp_name);
    return -1;
  }

  try {
    self->cxx->setInputDivision(*PyBlitzArrayCxx_AsBlitz<double,1>(input_divide));
  }
  catch (std::exception& ex) {
    PyErr_SetString(PyExc_RuntimeError, ex.what());
    return -1;
  }
  catch (...) {
    PyErr_Format(PyExc_RuntimeError, "cannot reset `input_divide' of %s: unknown exception caught", Py_TYPE(self)->tp_name);
    return -1;
  }

  return 0;

}

PyDoc_STRVAR(s_shape_str, "shape");
PyDoc_STRVAR(s_shape_doc,
"A tuple that represents the size of the input vector\n\
followed by the size of the output vector in the format\n\
``(input, output)``.\n\
");

static PyObject* PyBobLearnLibsvmMachine_getShape
(PyBobLearnLibsvmMachineObject* self, void* /*closure*/) {
  return Py_BuildValue("(nn)", self->cxx->inputSize(),
      self->cxx->outputSize());
}

PyDoc_STRVAR(s_labels_str, "labels");
PyDoc_STRVAR(s_labels_doc, "The class labels this machine will output");

static PyObject* PyBobLearnLibsvmMachine_getLabels
(PyBobLearnLibsvmMachineObject* self, void* /*closure*/) {
  PyObject* retval = PyList_New(self->cxx->numberOfClasses());
  for (size_t k=0; k<self->cxx->numberOfClasses(); ++k) {
    PyList_SET_ITEM(retval, k, Py_BuildValue("i", self->cxx->classLabel(k)));
  }
  return retval;
}

PyDoc_STRVAR(s_svm_type_attr_str, "svm_type");
PyDoc_STRVAR(s_svm_type_attr_doc, "The type of SVM machine contained");

static PyObject* PyBobLearnLibsvmMachine_getSvmType
(PyBobLearnLibsvmMachineObject* self, void* /*closure*/) {
  PyObject* retval = 0;
  switch(self->cxx->machineType()) {
    case bob::learn::libsvm::Machine::C_SVC:
      return Py_BuildValue("s", "C_SVC");
    case bob::learn::libsvm::Machine::NU_SVC:
      return Py_BuildValue("s", "NU_SVC");
    case bob::learn::libsvm::Machine::ONE_CLASS:
      return Py_BuildValue("s", "ONE_CLASS");
    case bob::learn::libsvm::Machine::EPSILON_SVR:
      return Py_BuildValue("s", "EPSILON_SVR");
    case bob::learn::libsvm::Machine::NU_SVR:
      return Py_BuildValue("s", "NU_SVR");
  }

  // if you get to this point, an error occurred somewhere - corruption?
  PyErr_Format("`%s' has a machine type which is not legal (%d) - DEBUG ME",
      Py_TYPE(self)->tp_name, (int)self->cxx->machineType());
  return 0;
}

PyDoc_STRVAR(s_svm_kernel_type_attr_str, "kernel_type");
PyDoc_STRVAR(s_svm_kernel_type_attr_doc,
"The type of kernel used by the support vectors in this machine");

static PyObject* PyBobLearnLibsvmMachine_getSvmKernelType
(PyBobLearnLibsvmMachineObject* self, void* /*closure*/) {
  PyObject* retval = 0;
  switch(self->cxx->kernelType()) {
    case bob::learn::libsvm::Machine::LINEAR:
      return Py_BuildValue("s", "LINEAR");
    case bob::learn::libsvm::Machine::POLY:
      return Py_BuildValue("s", "POLY");
    case bob::learn::libsvm::Machine::RBF:
      return Py_BuildValue("s", "RBF");
    case bob::learn::libsvm::Machine::SIGMOID:
      return Py_BuildValue("s", "SIGMOID");
    case bob::learn::libsvm::Machine::PRECOMPUTED:
      return Py_BuildValue("s", "PRECOMPUTED");
  }

  // if you get to this point, an error occurred somewhere - corruption?
  PyErr_Format("`%s' has a kernel type which is not legal (%d) - DEBUG ME",
      Py_TYPE(self)->tp_name, (int)self->cxx->machineType());
  return 0;
}

static PyGetSetDef PyBobLearnLibsvmMachine_getseters[] = {
    {
      s_input_subtract_str,
      (getter)PyBobLearnLibsvmMachine_getInputSubtraction,
      (setter)PyBobLearnLibsvmMachine_setInputSubtraction,
      s_input_subtract_doc,
      0
    },
    {
      s_input_divide_str,
      (getter)PyBobLearnLibsvmMachine_getInputDivision,
      (setter)PyBobLearnLibsvmMachine_setInputDivision,
      s_input_divide_doc,
      0
    },
    {
      s_shape_str,
      (getter)PyBobLearnLibsvmMachine_getShape,
      0,
      s_shape_doc,
      0
    },
    {
      s_labels_str,
      (getter)PyBobLearnLibsvmMachine_getLabels,
      0,
      s_labels_doc,
      0
    },
    {
      s_svm_type_attr_str,
      (getter)PyBobLearnLibsvmMachine_getSvmType,
      0,
      s_svm_type_attr_doc,
      0
    },
    {
      s_svm_kernel_type_attr_str,
      (getter)PyBobLearnLibsvmMachine_getSvmKernelType,
      0,
      s_svm_kernel_type_attr_doc,
      0
    },
    {0}  /* Sentinel */
};

#if PY_VERSION_HEX >= 0x03000000
#  define PYOBJECT_STR PyObject_Str
#else
#  define PYOBJECT_STR PyObject_Unicode
#endif

PyObject* PyBobLearnLibsvmMachine_Repr(PyBobLearnLibsvmMachineObject* self) {

  /**
   * Expected output:
   *
   * <xbob.learn.libsvm.Machine float64@(3, 2)>
   */

  auto shape = make_safe(PyObject_GetAttrString((PyObject*)self, "shape"));
  auto shape_str = make_safe(PyObject_Str(shape.get()));

  PyObject* retval = PyUnicode_FromFormat("<%s float64@%U>",
      Py_TYPE(self)->tp_name, shape_str.get());

#if PYTHON_VERSION_HEX < 0x03000000
  if (!retval) return 0;
  PyObject* tmp = PyObject_Str(retval);
  Py_DECREF(retval);
  retval = tmp;
#endif

  return retval;

}

PyObject* PyBobLearnLibsvmMachine_Str(PyBobLearnLibsvmMachineObject* self) {

  /**
   * Expected output:
   *
   * xbob.learn.libsvm.Machine (float64) 3 inputs, 2 outputs
   *   properties...
   *
   * TODO: Not fully implemented yet
   */

  return PyBobLearnLibsvmMachine_Repr(self);

}

PyDoc_STRVAR(s_forward_str, "forward");
PyDoc_STRVAR(s_forward_doc,
"o.forward(input [, output]) -> array\n\
\n\
Calculates the **predicted class** using this Machine, given\n\
one single feature vector or multiple ones.\n\
\n\
The ``input`` array can be either 1D or 2D 64-bit float arrays.\n\
The ``output`` array, if provided, must be of type ``int64``,\n\
always uni-dimensional. The output corresponds to the predicted\n\
classes for each of the input rows.\n\
\n\
.. note::\n\
\n\
   This method only accepts 64-bit float arrays as input and\n\
   64-bit integers as output.\n\
\n");

static PyObject* PyBobLearnLibsvmMachine_forward
(PyBobLearnLibsvmMachineObject* self, PyObject* args, PyObject* kwds) {

  static const char* const_kwlist[] = {"input", "output", 0};
  static char** kwlist = const_cast<char**>(const_kwlist);

  PyBlitzArrayObject* input = 0;
  PyBlitzArrayObject* output = 0;

  if (!PyArg_ParseTupleAndKeywords(args, kwds, "O&|O&", kwlist,
        &PyBlitzArray_Converter, &input,
        &PyBlitzArray_OutputConverter, &output
        )) return 0;

  //protects acquired resources through this scope
  auto input_ = make_safe(input);
  auto output_ = make_xsafe(output);

  if (input->type_num != NPY_FLOAT64) {
    PyErr_Format(PyExc_TypeError, "`%s' only supports 64-bit float arrays for input array `input'", Py_TYPE(self)->tp_name);
    return 0;
  }

  if (output && output->type_num != NPY_INT64) {
    PyErr_Format(PyExc_TypeError, "`%s' only supports 64-bit integer arrays for output array `output'", Py_TYPE(self)->tp_name);
    return 0;
  }

  if (input->ndim < 1 || input->ndim > 2) {
    PyErr_Format(PyExc_TypeError, "`%s' only accepts 1 or 2-dimensional arrays (not %" PY_FORMAT_SIZE_T "dD arrays)", Py_TYPE(self)->tp_name, input->ndim);
    return 0;
  }

  if (output && output->ndim != 1) {
    PyErr_Format(PyExc_RuntimeError, "Output arrays should always be 1D but you provided an object with %" PY_FORMAT_SIZE_T "d dimensions", output->ndim);
    return 0;
  }

  if (input->ndim == 1) {
    if (input->shape[0] != (Py_ssize_t)self->cxx->inputSize()) {
      PyErr_Format(PyExc_RuntimeError, "1D `input' array should have %" PY_FORMAT_SIZE_T "d elements matching `%s' input size, not %" PY_FORMAT_SIZE_T "d elements", self->cxx->inputSize(), Py_TYPE(self)->tp_name, input->shape[0]);
      return 0;
    }
    if (output && output->shape[0] != 1) {
      PyErr_Format(PyExc_RuntimeError, "1D `output' array should have 1 element, not %" PY_FORMAT_SIZE_T "d elements", output->shape[0]);
      return 0;
    }
  }
  else {
    if (input->shape[1] != (Py_ssize_t)self->cxx->inputSize()) {
      PyErr_Format(PyExc_RuntimeError, "2D `input' array should have %" PY_FORMAT_SIZE_T "d columns, matching `%s' input size, not %" PY_FORMAT_SIZE_T "d elements", self->cxx->inputSize(), Py_TYPE(self)->tp_name, input->shape[1]);
      return 0;
    }
    if (output && input->shape[0] != output->shape[0]) {
      PyErr_Format(PyExc_RuntimeError, "1D `output' array should have %" PY_FORMAT_SIZE_T "d elements matching the number of rows on `input', not %" PY_FORMAT_SIZE_T "d rows", input->shape[0], output->shape[0]);
      return 0;
    }
  }

  /** if ``output`` was not pre-allocated, do it now **/
  if (!output) {
    Py_ssize_t osize = 1;
    if (input->ndim == 2) osize = input->shape[0];
    output = (PyBlitzArrayObject*)PyBlitzArray_SimpleNew(NPY_INT64, 1, &osize);
    output_ = make_safe(output);
  }

  /** all basic checks are done, can call the machine now **/
  try {
    if (input->ndim == 1) {
      auto bzout = PyBlitzArrayCxx_AsBlitz<int64_t,1>(output);
      (*bzout)(0) = self->cxx->predictClass_(*PyBlitzArrayCxx_AsBlitz<double,1>(input));
    }
    else {
      auto bzin = PyBlitzArrayCxx_AsBlitz<double,2>(input);
      auto bzout = PyBlitzArrayCxx_AsBlitz<int64_t,2>(output);
      blitz::Range all = blitz::Range::all();
      for (int k=0; k<bzin->extent(0); ++k) {
        blitz::Array<double,1> i_ = (*bzin)(k, all);
        (*bzout)(k) = self->cxx->predictClass_(i_); ///< no need to re-check
      }
    }
  }
  catch (std::exception& e) {
    PyErr_SetString(PyExc_RuntimeError, e.what());
    return 0;
  }
  catch (...) {
    PyErr_Format(PyExc_RuntimeError, "%s cannot forward data: unknown exception caught", Py_TYPE(self)->tp_name);
    return 0;
  }

  Py_INCREF(output);
  return PyBlitzArray_NUMPY_WRAP(reinterpret_cast<PyObject*>(output));

}

PyDoc_STRVAR(s_save_str, "save");
PyDoc_STRVAR(s_save_doc,
"o.save(path) -> None\n\
\n\
o.save(hdf5file) -> None\n\
\n\
Saves itself at a LIBSVM model file or into a\n\
:py:class:`xbob.io.HDF5File`. Saving the SVM into an\n\
:py:class:`xbob.io.HDF5File` object, has the advantage of saving\n\
input normalization options together with the machine, which are\n\
automatically reloaded when you re-initialize it from the same\n\
:py:class:`HDF5File`.\n\
");

static PyObject* PyBobLearnLibsvmMachine_Save
(PyBobLearnLibsvmMachineObject* self, PyObject* f) {

  if (PyBobIoHDF5File_Check(f)) {
    auto h5f = reinterpret_cast<PyBobIoHDF5FileObject*>(f);
    try {
      self->cxx->save(*h5f->f);
    }
    catch (std::exception& e) {
      PyErr_SetString(PyExc_RuntimeError, e.what());
      return 0;
    }
    catch (...) {
      PyErr_Format(PyExc_RuntimeError, "`%s' cannot write data to file `%s' (at group `%s'): unknown exception caught", Py_TYPE(self)->tp_name,
          h5f->f->filename().c_str(), h5f->f->cwd().c_str());
      return 0;
    }
    Py_RETURN_NONE;
  }

  // try a filename conversion and use libsvm's original file format
  PyObject* filename = 0;
  int ok = PyBobIo_FilenameConverter(f, &filename);
  if (!ok) {
    PyErr_Format(PyExc_TypeError, "cannot convert `%s' into a valid string for a file path - objects of type `%s' can only save to HDF5 files or text files using LIBSVM's original file format (pass a string referring to a valid filesystem path in this case)", Py_TYPE(f)->tp_name, Py_TYPE(self)->tp_name);
    return 0;
  }

  // at this point we know we have a valid file system string
  auto filename_ = make_safe(filename);

#if PY_VERSION_HEX >= 0x03000000
  const char* c_filename = PyBytes_AS_STRING(filename);
#else
  const char* c_filename = PyString_AS_STRING(filename);
#endif

  try {
    self->cxx->save(c_filename);
  }
  catch (std::exception& ex) {
    PyErr_SetString(PyExc_RuntimeError, ex.what());
    return 0;
  }
  catch (...) {
    PyErr_Format(PyExc_RuntimeError, "`%s' cannot write data to file `%s' (using LIBSVM's original text format): unknown exception caught", Py_TYPE(self)->tp_name, c_filename);
    return 0;
  }

  Py_RETURN_NONE;

}

PyDoc_STRVAR(s_predict_class_str, "predict_class");

static PyMethodDef PyBobLearnLibsvmMachine_methods[] = {
  {
    s_forward_str,
    (PyCFunction)PyBobLearnLibsvmMachine_forward,
    METH_VARARGS|METH_KEYWORDS,
    s_forward_doc
  },
  {
    s_predict_class_str,
    (PyCFunction)PyBobLearnLibsvmMachine_forward,
    METH_VARARGS|METH_KEYWORDS,
    s_forward_doc
  },
  {
    s_save_str,
    (PyCFunction)PyBobLearnLibsvmMachine_Save,
    METH_O,
    s_save_doc
  },
  {0} /* Sentinel */
};

static PyObject* PyBobLearnLibsvmMachine_new
(PyTypeObject* type, PyObject*, PyObject*) {

  /* Allocates the python object itself */
  PyBobLearnLibsvmMachineObject* self =
    (PyBobLearnLibsvmMachineObject*)type->tp_alloc(type, 0);

  self->cxx = 0;

  return reinterpret_cast<PyObject*>(self);

}

PyTypeObject PyBobLearnLibsvmMachine_Type = {
    PyVarObject_HEAD_INIT(0, 0)
    s_svm_str,                                        /* tp_name */
    sizeof(PyBobLearnLibsvmMachineObject),            /* tp_basicsize */
    0,                                                /* tp_itemsize */
    (destructor)PyBobLearnLibsvmMachine_delete,       /* tp_dealloc */
    0,                                                /* tp_print */
    0,                                                /* tp_getattr */
    0,                                                /* tp_setattr */
    0,                                                /* tp_compare */
    (reprfunc)PyBobLearnLibsvmMachine_Repr,           /* tp_repr */
    0,                                                /* tp_as_number */
    0,                                                /* tp_as_sequence */
    0,                                                /* tp_as_mapping */
    0,                                                /* tp_hash */
    (ternaryfunc)PyBobLearnLibsvmMachine_forward,     /* tp_call */
    (reprfunc)PyBobLearnLibsvmMachine_Str,            /* tp_str */
    0,                                                /* tp_getattro */
    0,                                                /* tp_setattro */
    0,                                                /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,         /* tp_flags */
    s_svm_doc,                                        /* tp_doc */
    0,                                                /* tp_traverse */
    0,                                                /* tp_clear */
    0,                                                /* tp_richcompare */
    0,                                                /* tp_weaklistoffset */
    0,                                                /* tp_iter */
    0,                                                /* tp_iternext */
    PyBobLearnLibsvmMachine_methods,                  /* tp_methods */
    0,                                                /* tp_members */
    PyBobLearnLibsvmMachine_getseters,                /* tp_getset */
    0,                                                /* tp_base */
    0,                                                /* tp_dict */
    0,                                                /* tp_descr_get */
    0,                                                /* tp_descr_set */
    0,                                                /* tp_dictoffset */
    (initproc)PyBobLearnLibsvmMachine_init,           /* tp_init */
    0,                                                /* tp_alloc */
    PyBobLearnLibsvmMachine_new,                      /* tp_new */
};
