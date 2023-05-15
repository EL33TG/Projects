/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File option4.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"


/*
* Function: option4
* -------------------------
* Option4 - Recalculate Student Scores for a Single Student ID - (Called from user_interface.c)
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char** The categories Address location
* ...
*
* returns: nothing
*
*/
void option4(Node *list_head, char categories[][40]){
    
      int studentID,i,j,flag;           /* setting int values for use */
      Node *traversePtr = list_head;    /* setting new head to pointer to original list address */
      struct Cat_Grade *cat;            /* pointer to struct member to help with value iteration */
      float *score;                     /* pointer to help with value iteration*/
      const int CURRENT = 100;          /* setting constant variable for calculation (100 or 0) */
      flag = 0;                         /* setting flag for loop position indicator */
      
      printf("We will recalculate grade for student\n");
      printf("Enter the Student ID #: ");
      scanf("%d", &studentID);
      printf("Hunting for %d\n", studentID);
    
    printHeader(categories);            /* Print initial header output */
    
      while(traversePtr != NULL && flag != 1)
      {
          if (traversePtr->Student.student_ID == studentID){

              printf("\n%s\t\t%d\t\t \n", traversePtr->Student.student_name,traversePtr->Student.student_ID);
              printf("\t\t\t\t");
              cat = &(traversePtr->Student.Cat1);
              score = &(cat->score1);
              
              
              for (i=0; i<4;i++){
                 
                  populateScores(traversePtr, i);            /* calculate scores */
              }
              
              traversePtr->Student.Current_Grade = populateGrade(traversePtr, CURRENT); /* calculate grade */
              
              for (i=0; i<6;i++){
                             for (j=0;j<3;j++, score++){
                          
                                     printf("%.2f\t", *score);
                             }
                         }
              
              flag = 1;
              
          } else {
              
              traversePtr = traversePtr->next;
          }
          
      }
}
