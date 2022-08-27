// Abstract data type design pattern demo
// This model can be used for building an API if "file.c" API is embeded in a DLL (encapsulation)
// All the implementation details are located in file.c
// The header contain everything you need to work with the API file.h
// 
// To use the lib you must declare a HTEXTFILE handle following by a init_file() method that instanciate the object (struct)
// After initialization you can use other fonctions like write_file()
// When you don't need the object anymore you have to clean it with close_file() method


#include "file.h"

#ifdef _DEBUG
int main(void)
{
	HTEXTFILE hFile = NULL;															// Create handle to the object hFile of type HTEXTFILE
	hFile = init_file((LPSTR)"Test.txt");											// Init the file by creating the file on disk and open it
	write_file(hFile, (LPSTR)"Text inside the file\n");								// Write text inside the file
	close_file(hFile);																// Close the file
	return EXIT_SUCCESS;															// Exiting with success
}

#else
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )  
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE; 
}
#endif