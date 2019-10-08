#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lotForSale{
    int lot_number;
    float lot_cost;
    float square_footage;
};

typedef struct Student90COS {
    char student_initials[4];
    int student_number;
    struct Student90COS * next_node;
    struct Student90COS * previous_node;
} node;

void spillList(node *n);
void reverseList(node *n);

int main(void){
    // How to initialize and assign a structure
    struct lotForSale timberRange = {8755, 2500, 6534};
    timberRange.lot_cost = 9999;
    timberRange.square_footage = 1215.5;

    //LotForSale variable
    struct lotForSale millionaireEstates;

    //LotForSale variable
    struct lotForSale countrysideAcres;

    struct lotForSale * currentLot = &millionaireEstates;

    //Define first member
    currentLot->lot_number = 1000000;

    //Define second member
    currentLot->lot_cost = 1000000;

    //Define third member
    currentLot->square_footage = 1000000;


    // How to use a typedef
    typedef struct{
        char student_name[256];
        int age;
    } Student;

    Student guy1 = {"Someone", 32};
    Student guy2 = {"Someone Else", 24};

    Student * guy3 = (Student*)malloc(sizeof(Student));
    strcpy(guy3->student_name, "Someone");

    // Using a struct array
    Student class[3] = {guy1, guy2, *guy3};

    // Creating a linked list
    node * MQT18_01_S1 = (node*)malloc(sizeof(node));
    node * MQT18_01_S2 = (node*)malloc(sizeof(node));
    node * MQT18_01_S3 = (node*)malloc(sizeof(node));

    strcpy(MQT18_01_S1->student_initials, "LOL");
    MQT18_01_S1->student_number = 1;
    MQT18_01_S1->previous_node = NULL;
    MQT18_01_S1->next_node = MQT18_01_S2;

    strcpy(MQT18_01_S2->student_initials, "KAY");
    MQT18_01_S2->student_number = 2;
    MQT18_01_S2->previous_node = MQT18_01_S1;
    MQT18_01_S2->next_node = MQT18_01_S3;

    strcpy(MQT18_01_S3->student_initials, "YAY");
    MQT18_01_S3->student_number = 3;
    MQT18_01_S3->previous_node = MQT18_01_S2;
    MQT18_01_S3->next_node = NULL;

    spillList(MQT18_01_S1);
    reverseList(MQT18_01_S3);
    return 0;
}

void spillList(node *n)
{
    printf("Starting on student with initials: %s\n", n->student_initials);
    while (n != NULL)
    {
        printf("%d: %s\n", n->student_number, n->student_initials);
        n = n->next_node;
    }
}

void reverseList(node *n)
{
    printf("Starting on student with initials: %s\n", n->student_initials);
    while (n != NULL)
    {
        printf("%d: %s\n", n->student_number, n->student_initials);
        n = n->previous_node;
    }
}
