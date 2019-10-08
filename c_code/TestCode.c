#include <Windows.h>
#include <stdio.h>
#include "TestCode.h"

/////////////////////////////////////////////////////////////
// Test 1: For this task, you will receive two pointers to NULL terminated strings: 
//		   a 'sentence', and a 'word'. The objective will be to delete (in place) the first 
//		   occurrence of 'word' in the sentence. 
//
// Expected Return Values:
//		- the task is successful: should return ERROR_SUCCESS (0).
//		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
//		- the provided 'word' is not part of 'sentence': should return ERROR_NOT_FOUND (1168)
/////////////////////////////////////////////////////////////

int deleteWord(char* sentence, char* word)
{
	int status = ERROR_SUCCESS; // May want to replace this at some point
	if (word == NULL || sentence == NULL) {
		status = ERROR_INVALID_PARAMETER;
	}
	else if (strstr(sentence, word) == NULL) {
		status = ERROR_NOT_FOUND;
	}
	else {
		char *match;
		int len = strlen(word);
		while ((match = strstr(sentence, word))) {
			*match = '\0';
			strcat(sentence, match + len);
		}
	}
	return status;
}


/////////////////////////////////////////////////////////////
// Test 3 (part one): This task will involve allocating a buffer
//				of (sizeOfData) bytes, and reading up to that amount
//				into it from the file specified in 'filename'. Additionally,
//				the data in the file has been pseudo-encryped (poorly) with a single-
//				byte XOR, which you will be required to undo (the byte that the buffer
//				was XOR'd against will be provided in 'key'). Finally, assuming the task
//				was successful, (and all pointers are valid) the pointer to the resulting 
//				buffer should be stored in the area referenced by buffPtr.
//
// Expected Return Values:
//			- task was completed successfully: ERROR_SUCCESS (0)
//			- bad input was provided: ERROR_INVALID_PARAMETER (87)
//			- you were unable to allocate enough memory: ERROR_OUTOFMEMORY (14)
//			- you were unable to open the file: ERROR_OPEN_FAILED (110)
/////////////////////////////////////////////////////////////
int decodeFromFile(char* filename, unsigned int sizeOfData, unsigned char key, void** buffPtr)
{
	printf("--------------------------Starting Test #3-----------------------------------------------\n");
	int status = ERROR_SUCCESS; // May want to replace this at some point
	char *xor = malloc(sizeof(char)*sizeOfData + 1);

	// Allocate memory for the buffer, then check if the memory could be allocated
	char *buffer = malloc(sizeof(char)*sizeOfData + 1);
	if (buffer == NULL) {
		printf("The buffer could not be created\n");
		status = ERROR_OUTOFMEMORY;
		return status;
	}

	printf("Filename: %s\n", filename);
	// Check that the filename is not null
	if (filename == NULL || sizeOfData == NULL || key == NULL || buffPtr == NULL) {
		printf("Found invalid file\n");
		status = ERROR_INVALID_PARAMETER;
		return status;
	}
	
	// Open file and check if the file can be opened
	FILE * file_ptr = fopen(filename, "r");
	printf("key: %d\nsize: %d\n", key, sizeOfData -1);
	if (file_ptr != NULL) {
		printf("Reading from file: %s\n", filename);
		fread(buffer, 1, sizeOfData, file_ptr);
		for (int i = 0; i < sizeOfData; ++i) {
			xor[i] = buffer[i] ^ key;
		}
		xor[sizeOfData] = '\0';
		printf("%d\n", sizeof(xor));
		// Store data in area pointed to by buffPtr
		printf("Buffer Address: %x\n", &buffPtr);
		strcpy(*buffPtr, &xor);
		printf("Buffer Address: %x\n", buffPtr);
		printf("xor Address: %x\n", &xor);


	fclose(file_ptr);
	} else {
		printf("The file did not exists\n");
		status = ERROR_OPEN_FAILED;
		return status;
	}

	// Free the buffer
	free(buffer);
	free(xor);
	return status;
}

/////////////////////////////////////////////////////////////
// Test 3 (part two): The second part of the task; this simply requires you
//				  to appropriately free the buffer allocated in the last task
//				  (if possible).
//
// Expected Return Values:
//			- the task completed successfully: TRUE
//			- the task failed/bad input: FALSE
/////////////////////////////////////////////////////////////
BOOL freeDecodedBuffer(void* buffer)
{
	BOOL out = FALSE; // May want to replace this at some point
	if (buffer != NULL) {
		free(buffer);
		buffer = NULL;
	}
	return out;
}


// Solution from practice example
int decodeFromFile(char* filename, unsigned int sizeOfData, unsigned char key, void** buffPtr)
{
    if (filename == NULL) {
        return ERROR_INVALID_PARAMETER;
    } else if (buffPtr == NULL) {
        return ERROR_INVALID_PARAMETER;
    }
    int status = ERROR_SUCCESS;
    char* reservedMem = malloc(sizeOfData);
    FILE *filePtr;
    filePtr = fopen(filename, "r");
    if (reservedMem == NULL) {
        return ERROR_OUTOFMEMORY;
    }
    if (filePtr == NULL) {
        return ERROR_OPEN_FAILED;
    }
    fgets(reservedMem, sizeOfData, filePtr);
    for (int i = 0; i < sizeOfData; i++) {
        reservedMem[i] ^ key;
    }
    buffPtr = *reservedMem; //buffer pointer now points to reserved Mem buffer.
    fclose(filePtr);
    return status;

}
