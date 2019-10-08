# include <stdio.h>

int main(){
    // Basic if-else/if-else conditional
    int i = 0;
    if (i) {
        printf("This shouldn't ever print");
    } else if (i==3){
        printf("This shouldn't print either");
    } else {
        printf("This should always print");
    }

    // Switch statements
    int my_var = 0;
    scanf("%*c%d%*c", &my_var);
    switch (my_var){
        case 1:
            printf("Statement #1 hit");
            break;
        case 2:
            printf("Statement #2 hit");
            break;
        default:
            printf("Default Statement hit");
            break;
    }
}