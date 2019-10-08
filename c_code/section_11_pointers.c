#include <stdio.h>

int main(){
    // How to set a hex number
    unsigned int fullInteger = 0xABCD1234;

    // Pointer tutorial -- Memory Address
    int var = 42;
    printf("Value of the variable var is: %d\n", var);
    printf("Memory address of the variable var is: 0x%x\n", &var);

    // Pointer variable -- Initialize
    int *ip = NULL; //Pointer to integer variable
    float *fp = NULL; //Pointer to float variable
    double *dp = NULL; //Pointer to double variable
    char *cp = NULL; //Pointer to char variable

    // Pointer initialization
    ip = &var;

    // Dereferencing of Pointer
    printf("%d\n", *ip); // Prints the value of ip
    printf("%d\n", *&var); // Prints the value of var
    printf("0x%x\n", &var); // Prints the address of var

    // Double Pointers
    int *ptr; // Pointer -- will assign to var's address
    int **dblPtr; // Double Pointer -- will point to the pointer
    ptr = &var; // Store address of the integer
    dblPtr = &ptr; // Store address of ptr into dblPtr

    printf("Value of var: %d\n", var);
    printf("Value of var using ptr: %d\n", *ptr);
    printf("Value of var using dblPtr: %d\n", **dblPtr);

    return 0;
}