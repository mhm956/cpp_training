# include <stdio.h>
# include "My_Local_Header.h"

# define MY_HEADER_YES 1
# define MY_HEADER_NO 0

#ifdef _WIN32
# define _CRT_SECURE_NO_WARNINGS 1
# include Windows.h
#endif

/*
 * static - a global definition that can only be seen in this file
 * extern - a global definition that can be seen from any file
 */

extern int is_larger(int a, int b){
    if (a > b){
        return MY_HEADER_YES;
    } else {
        return MY_HEADER_NO;
    }
}

char scope[] = {"Global\n"};

int main(){
    /******* General Function *******/
    int i = 0; // iterating the var
    printf("%s", scope);

    //this array is local to main()
    char scope[] = {"main\n"};
    printf("%s", scope);
    for(i = 0; i < 3; i++){
        char scope[] = {"for\n"};
        printf("%s", scope);
    }

    /******* Static & Extern Function *******/
    int firstNum, secondNum;
    // flushall(); // This only works for a Windows environment!
    scanf("is %d larger than %d?", &firstNum, &secondNum);

    if (is_larger(firstNum, secondNum)){
        printf("%d was larger\n", firstNum);
    } else {
        printf("%d was larger\n", secondNum);
    }

    return 0;
}