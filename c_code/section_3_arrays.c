//
// Created by tharper on 5/22/19.
//
#include <stdio.h>

int main() {
    // Make an array of student ages
    int class_size = 4;
    int students[4 + 1] = {0};
    students[0] = 22;
    students[1] = 21;
    students[2] = 25;
    students[3] = 21;
    int iii;
    for (iii = 0; iii < class_size; iii++){
        printf("Student #%d is %d years old\n", iii + 1, students[iii]);
    }

    // Make an array containing a quote
    char quote[20] = "To be, or not to be\0";
    for (iii = 0; iii < 20; iii++){
        printf("%c\n", quote[iii]);
    }


    char new_quote [6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("The new quote says: %s\n", new_quote);
    return 0;
}