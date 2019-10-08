#include <stdio.h>
#include <math.h>

double sqrt(double x);

int main(){
    // Hard vs Soft division
    int x = 5;
    int y = 3;
    printf("5/3 = %d?\n", x/y);
    printf("Now make it a float: %f\n", (float)x/y);

    // Modulo
    printf("5 %s 3 = %d\n", "%", 5%3);

    printf("Square Root of 8 is %lf\n", sqrt(8));
    return 0;
}