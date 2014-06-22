// DynamicLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DynamicLib.h"


// This is an example of an exported variable
DYNAMICLIB_API int nDynamicLib=0;

// This is an example of an exported function.
DYNAMICLIB_API int fnDynamicLib(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see DynamicLib.h for the class definition
CDynamicLib::CDynamicLib()
{
	return;
}

DYNAMICLIB_API int multiply(int a, int b)
{
  return a * b;
}