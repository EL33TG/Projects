/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File option3.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: option3
* -------------------------
* Option3 - Print Student Scores for All Students - (Called from user_interface.c)
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char** The categories Address location
* ...
*
* returns: nothing
*
*/

void option3(Node *list_head, char categories[][40]){
    
    int stdCount,i,j,flag;                  /* setting int values for use */
    Node *traversePtr = list_head;          /* setting new head to pointer to original list address */
    struct Cat_Grade *cat;                  /* pointer to struct member to help with value iteration */
    float *score,quiz,mid,home,fin,cur;     /* pointer to help with value iteration & variables to store totals */
    stdCount=quiz=mid=home=fin=cur = 0;     /* Initializing all values to 0 */
    flag=0;                                 /* setting flag for loop position indicator */

    printHeader(categories);                /* Print initial header output */
    
    while(traversePtr != NULL)
    {
        if (traversePtr != NULL){
            
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
            
            /* adding all values & sending to function to check for -1 value, if -1 adding 100 to score */
            
               quiz += checkForUnsignedValue(traversePtr->Student.Cat1.Cumulative);
               mid += checkForUnsignedValue(traversePtr->Student.Cat2.Cumulative);
               home += checkForUnsignedValue(traversePtr->Student.Cat3.Cumulative);
               fin += checkForUnsignedValue(traversePtr->Student.Cat4.Cumulative);
               cur += checkForUnsignedValue(traversePtr->Student.Current_Grade);

                stdCount++;
            
            
        }
        traversePtr = traversePtr->next;
        
    }
                /* print dividing totals by count of students & print */
    printf("\n\nClass Averages for Quizzes: %.2f, Midterms: %.2f, Homework: %.2f, Final: %.2f, Current Grade: %.2f\n", (quiz/stdCount),(mid/stdCount),(home/stdCount),(cur/stdCount),(fin/stdCount));

}



/*
* Function: checkForUnsignedValue
* -------------------------
* checkForUnsignedValue - Print Student Scores for All Students - (Called from user_interface.c)
*
* Parameter 1: float - The listeHead Address location
* ...
*
* returns: Returns the value as a float
*
*/
float checkForUnsignedValue(float value){
    
    float holder = 0;
    
        if(value == -1){
            holder = holder + 100;      /* adding 100 to value where -1 exist */
        } else {
            holder = holder + value;    /* incrementing value */
        }
    return holder;
}
