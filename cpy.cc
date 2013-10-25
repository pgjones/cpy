#include <Python.h>

#include <iostream>
using namespace std;

int main( int argc, char** argv )
{
  Py_Initialize();

  PyObject* pScriptName = PyString_FromString( "pyfunc" );
  PyObject* pScript = PyImport_Import( pScriptName ); // Load script
  Py_DECREF( pScriptName );
  PyObject* pFunction = PyObject_GetAttrString( pScript, "funct" );
  if( !pFunction || !PyCallable_Check( pFunction ) )
    throw;
  PyObject* pResult = PyObject_CallFunctionObjArgs( pFunction, NULL );
  for( size_t iObjects = 0; iObjects < PyList_Size( pResult ); iObjects++ )
    cout << PyString_AsString( PyList_GetItem( pResult, iObjects ) ) << endl;
  PyObject* pResult2 = PyObject_CallFunctionObjArgs( pFunction, pResult, NULL );
  Py_DECREF( pResult );
  for( size_t iObjects = 0; iObjects < PyList_Size( pResult2 ); iObjects++ )
    cout << PyString_AsString( PyList_GetItem( pResult2, iObjects ) ) << endl;

  Py_DECREF( pResult );
  Py_DECREF( pFunction );
  Py_DECREF( pScript );

  Py_Finalize();
}
