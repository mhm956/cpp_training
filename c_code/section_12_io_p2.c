#include <stdio.h>

int main(){
    /* open a file for writing */
    FILE * writeFile_ptr = fopen("write-file.txt", "w");

    /* verify the file opened */
    if(writeFile_ptr != NULL) {
        //[...file operations...]
        fclose(writeFile_ptr);  //always fclose anything you fopen
    }
    else {
        puts("ERROR opening file!");
        return -1;
    }
    return 0;
}