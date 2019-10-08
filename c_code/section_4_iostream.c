// Section 4: IO Introduction for C

#include <stdio.h>

int main() {
    // getchar -- Get a character from the stdin
    int userInput = 0;
    printf("Enter a character: ");
    userInput = getchar();
    printf("\nYour character was: ");
    // putchar -- Print a character to stdout
    putchar(userInput);

    // Not currently working...
    // fgets -- read n-1 chars from stream into buffer str

    // How to print the float with certain precision
    float someNum = 12.3456;
    printf("%f\n", someNum);
    printf("%.0f\n", someNum);
    printf("%.6f\n", someNum);
    printf("%.12f\n", someNum);

    char myStr[] = {"Hello World!"};
    printf("%s\n", myStr);
    printf("%.5s\n", myStr);

    // scanf - Reach characters from stdin and saves converted values into argument-1 ... argument-n
    int num = 0;
    char letter = 0;
    printf("Enter a number and a letter: ");
    scanf("%d%c", &num, &letter);
    printf("Number: %d --- Letter: %s", num, &letter);

    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    // The %*c conversion specification tells scanf to read chars in between integers but doesn't assign it to a variable.
    printf("\nEnter a time {XX:XX:XX}: ");
    scanf("%d%*c%d%*c%d", &hours, &minutes, &seconds);
    printf("Hour: %d -- Minutes: %d -- Seconds: %d\n", hours, minutes, seconds);
    return 0;
}