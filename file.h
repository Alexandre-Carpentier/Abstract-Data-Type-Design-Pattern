// Public declaration goes here

#ifndef _FILE_H__
#define _FILE_H__
#include <windows.h>

// Abstract data type definition: What is HFILE is not my buissness

typedef void* HTEXTFILE;

// Declaration of the public method to access the object: Only this methods are accessible externally

HTEXTFILE init_file(LPSTR szFile);
BOOL write_file(HTEXTFILE hFile, LPSTR text);
BOOL close_file(HTEXTFILE hFile);

#endif
