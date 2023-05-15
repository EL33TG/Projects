/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/
/*
*
* lab4.h (file location)
*
* Author: Brenden Boswell
*
* Header
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
* Struct: Cat_Grade
*
* Member 1: float score1;
* Member 2: float score2;
* Member 3: float score3;
* Member 4: float Cumulative;
*
* Holds all score information for a student
*/
struct Cat_Grade{
    float score1;
    float score2;
    float score3;
    float Cumulative;
};

/*
* Struct: Data
*
* Member 1: char student_name[40];
* Member 2: int student_ID;
* Member 3: struct Cat_Grade Cat1;
* Member 4: struct Cat_Grade Cat2;
* Member 5: struct Cat_Grade Cat3;
* Member 6: struct Cat_Grade Cat4;
* Member 7: float Current_Grade;
* Member 8: float Final_Grade;
*
* Holds structure members student information
*/
struct Data{
    char student_name[40];
    int student_ID;
    struct Cat_Grade Cat1;
    struct Cat_Grade Cat2;
    struct Cat_Grade Cat3;
    struct Cat_Grade Cat4;
    float Current_Grade;
    float Final_Grade;
};
/*
* Struct: Node
*
* Member 1: Data Student;
* Member 2: Node *next;
*
* Holds all the structure members & next address location
*/
typedef struct Node {
    struct Data Student;
    struct Node *next;
} Node;


                 
/* Starting point */
void user_interface(struct Node **list_head, char *filename1, char *filename2);
/* End of starting point */


/* Populate student node & associated data */
Node * create_student(struct Node **list_head, FILE *readTo);
void populateCategories(Node *newNodePtr, int inNum, FILE *readTo);
float populateGrade(Node *newNodePtr, int gradeType);
void populateScores(Node *newNodePtr, int inNum);
/* End of student node population */


/* All user options functions [1-7] available */
void option1(Node *list_head, char categories[][40]);
void option2(Node *list_head, char categories[][40]);
void option3(Node *list_head, char categories[][40]);
void option4(Node *list_head, char categories[][40]);
void option5(Node *list_head, char categories[][40]);
void option6(Node *list_head, char categories[][40]);
void option7(Node *list_head, char categories[][40]);
/* End of user options available */


/* Grab user input (integer value), later send value over to switch/case function */
int userOptions();
void executeUserOption(Node *newNodePtr, Node **list_head, int userChoice, char *filename2, char categories[][40]);
/* End */


/* All node insert/add/delete functions */
void saveStudentsToFile(Node **list_head, char *filename2, char categories[][40]);
void insert_node(Node **list_head, Node *newNodePtr);
void delete_node(Node **list_head, int studentID);
void freeAllNodes(Node **list_head);
/* end of nod manipulation */


/* function to check for -1 value & return a calculated result */
float checkForUnsignedValue(float value);
/* end*/

/* prints headers pre-formatted */
void printHeader(char categories[][40]);
/* header printing end */
