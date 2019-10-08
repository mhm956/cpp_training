#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// malloc() allocates size bytest and returns a pointer to the allocated memory. The memory is not initialized.
// void *malloc(size_t size)

// free() frees the memory space pointed t oby ptr, which must have been returned by a previous call to malloc(),
//  calloc(), or realloc().
// void free(void *ptr)

// calloc() allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated
//   memory. The memeory is set to zero.
// void *calloc(size_t nmemeb, size_t size);

// realloc() changes the size of the memory block pointed to by ptr to size bytes.
//   void *realloc(void *ptr, size_t size)

int main(void){
    char string[] = "Hello World";
    char substring[] = "World";
    char substring2[] = "Wo";

    printf("\n\n===== malloc() =====\n");
    char *buffer = malloc(strlen(string) + 1);
    if (!buffer){
        return 1;
    }

    printf("\n\n===== strcpy() ======\n");
    strcpy(buffer, string);
    printf("Buffer is now: %s\n\n", buffer);
    printf("String is still: %s\n", string);

    printf("\n\n===== strcmp() =====\n");
    if (strcmp(string, buffer) == 0){
        printf("Match!\n");
    } else {
        printf("Not a match!\n");
    }

    printf("\n\n===== memcpy() =====\n");
    char stackBuffer[50] = {0};
    printf("String in buffer before memcpy: %s\n", stackBuffer);
    memcpy(stackBuffer, string, strlen(string) +1);
    printf("String is: %s\n", string);
    printf("String in buffer after memcpy() is: %s\n", stackBuffer);

    printf("\n\n===== memmove() =====\n");
    char stackBuffer2[50] = {0};
    printf("String in buffer before memmove: %s\n", stackBuffer2);
    memmove(stackBuffer2, string, strlen(string) + 1);
    printf("String is: %s\n", string);
    printf("String in buffer after memmove: %s\n", stackBuffer2);

    printf("\n\n===== strstr() =====\n");
    char *mark_position = strstr(string, substring);
    printf("%s", mark_position);

    free(buffer);
    getchar();
    getchar();

    // Demo #1 Malloc
    int *integer_prt;
    // (type that we are storing in this memory)malloc(size of an integer)
    integer_prt = (int *)malloc(sizeof(int));
    if (integer_prt == 0){
        printf("Error: Not enough memory!");
        return 1;
    }
    // Set the dereference pointer to 20
    *integer_prt = 20;
    printf("The value is: %d\n", *integer_prt);
    free(integer_prt);
    integer_prt = NULL;
    return 0;

}