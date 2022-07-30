// Implementation and private data goes here (file.c)

#include "file.h"
#include <stdlib.h>
#include <stdio.h>

// the structure hold every informations needed by HTEXTFILE type

typedef struct {
	FILE* pFile;																		// Hold the file pointer descriptor
	char status[32];																	// Hold the current status of the object
	int text_max_len;
}FILESTRUCT, * PFILESTRUCT;																


HTEXTFILE init_file(LPSTR szFile)
{
	PFILESTRUCT pFileStruct = NULL;														// Declara a pointer to the object and initialize with NULL	
	pFileStruct = (PFILESTRUCT)malloc(sizeof(FILESTRUCT));								// Create the object in memory dynamically
	if (pFileStruct == NULL)															// Test if success
		return NULL;
	
// Check the path length 

	if (strnlen_s(szFile, MAX_PATH) == MAX_PATH)
		return NULL;

// Open the file

	if (fopen_s(&pFileStruct->pFile, szFile, "a+") != 0)
		return NULL;


// Update the status

	strcpy_s(pFileStruct->status, "Openned");

// Define a maximal characters length to write in the file

	pFileStruct->text_max_len = 1000;

// Returning pFileStruct abstracted as HTEXTFILE,
// in this way you hide the struct details implementation and only return pointer to HTEXTFILE

	return pFileStruct;
}

BOOL write_file(HTEXTFILE hFile, LPSTR text)
{
	if (hFile == NULL)																	// Check if the object is valid
		return NULL;

	PFILESTRUCT pFileStruct = (PFILESTRUCT)hFile;										// Cast hFile to the struct object
	if(strcmp(pFileStruct->status, "Openned") != 0)			
		return NULL;

	fwrite(text, sizeof(CHAR), strnlen_s(text, pFileStruct->text_max_len), pFileStruct->pFile);	// Write inside the file for a max amount of 1000 characters
	return TRUE;
}

BOOL close_file(HTEXTFILE hFile)
{
	if (hFile == NULL)
		return NULL;

	PFILESTRUCT pFileStruct = (PFILESTRUCT)hFile;										// Cast hFile to the struct object 
	fclose(pFileStruct->pFile);															// Close the file
	free(pFileStruct);																	// Free the struct from the allocated memory
	return TRUE;
}