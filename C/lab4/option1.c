/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File option1.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/

#include "lab4.h"
/*
* Function: option1
* -------------------------
* Option1 - Prints Student Scores by StudentID - (Called from user_interface.c)
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char** The categories Address location
* ...
*
* returns: nothing
*
*/
void option1(Node *list_head, char categories[][40]){
    int studentID,i,j, flag = 0;
    Node *traversePtr = list_head;
    
    struct Cat_Grade *cat;
    float *score;
    
    printf("Enter the Student ID #: ");
    scanf("%d", &studentID);
    printf("Hunting for %d\n", studentID);
    
    printHeader(categories);     /* Print initial header output */
    
    while(traversePtr != NULL && flag != 1)
    {
        if (traversePtr->Student.student_ID == studentID){
            
            printf("\n%s\t\t%d\t\t \n", traversePtr->Student.student_name,traversePtr->Student.student_ID);
            printf("\t\t\t\t");
            cat = &(traversePtr->Student.Cat1);
            score = &(cat->score1);
            
            
            for (i=0; i<6;i++){
                for (j=0;j<3;j++, score++){
                    if (*(score) == -1){
                        printf("  n/a\t");
                    } else {
                        printf("%.2f\t", *score);
                    }
                }
            }
            
            flag = 1;
            
        } else {
            
            traversePtr = traversePtr->next;
        }
        
    }
}
