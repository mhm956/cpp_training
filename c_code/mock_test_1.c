#include <string.h>
#include <stdio.h>
//
// Created by tharper on 6/5/19.
//

int main(void){
    char* sentence = {"Hello World"};
    char* word = {"World"};
    char *mark_position = strstr(sentence, word);
    printf("%s", mark_position);
    return 0;
}