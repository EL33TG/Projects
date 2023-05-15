/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File option6.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: option6
* -------------------------
* Option6 - Insert a score for a specific Student ID - (Called from user_interface.c)
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char** The categories Address location
* ...
*
* returns: nothing
*
*/
void option6(Node *list_head, char categories[][40]){
    
       int studentID,i,j,catNumber,scorePos,flag; /* setting int values for use */
       Node *traversePtr = list_head;             /* setting new head to pointer to original list address */
       struct Cat_Grade *cat, *addCat;            /* pointer to struct member to help with value iteration */
       float *score,*addScore, num;               /* pointer to help with value iteration & variables to store totals */
       flag = 0;                                  /* initializing flag to 0 */
       
       printf("Enter the Student ID #: ");
       scanf("%d", &studentID);
       printf("Which category would you ike this store in [1-4]?:\n");
       scanf("%d", &catNumber);
       printf("Which score postion would you ike this store in [1-3]?:\n");
       scanf("%d", &scorePos);
       printf("What value would you like to add:\n");
       scanf("%f", &num);
    
    
    printHeader(categories);                    /* Print initial header output */
    
    while(traversePtr != NULL && flag != 1)
       {
           if (traversePtr->Student.student_ID == studentID){
    
               addCat = &(traversePtr->Student.Cat1);
               addCat= (addCat + catNumber-1);
               addScore = &(addCat->score1);
               addScore = (addScore + scorePos-1) ;
               
               *(addScore) = num;
               
               printf("%s\t\t%d\t\t \n", traversePtr->Student.student_name,traversePtr->Student.student_ID);
               printf("\t\t\t\t");
               cat = &(traversePtr->Student.Cat1);
               score = &(cat->score1);
               
               
               for (i=0; i<5;i++){
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
