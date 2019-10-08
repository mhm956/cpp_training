#include <stdio.h>

int main() {
    // Get character from the keyboard
    // getchar();

    /***************************************************************************************************/
    // Section #3 -- Arrays
    // Declare an array, a char array 4 chars long
    char availableGrades[5] = "test";
    printf("This is a %s...\n", availableGrades);

    // Now doing the same thing with ints
    int test_scores[3] = {84, 73, 88};
    printf("The test score was %d\n", test_scores[2]);

    // Now going to modify the char array;
    availableGrades[0] = 'r';
    printf("This is a %s...\n", availableGrades);

    //
    /***************************************************************************************************/
    return 0;
}