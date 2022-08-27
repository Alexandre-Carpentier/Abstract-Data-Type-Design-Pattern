// Public declaration goes here

#ifndef _FILE_H__
#define _FILE_H__
#include <windows.h>

// Abstract data type definition: What is HFILE is not my buissness

typedef void* HTEXTFILE;

// Declaration of the public method to access the object: Only this methods are accessible externally

__declspec(dllexport) HTEXTFILE init_file(CONST LPSTR szFile);
__declspec(dllexport) BOOL write_file(CONST HTEXTFILE hFile, LPSTR text);
__declspec(dllexport) BOOL close_file(CONST HTEXTFILE hFile);

#endif
