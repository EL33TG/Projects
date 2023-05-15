/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File populate_scores.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"


/*
* Function: populateScores
* -------------------------
* populateScores - populates scores for student
*
* Parameter 1: Node* The Node Address location
* Parameter 2: int The int value to increment
* ...
*
* returns: nothing
*
*/
void populateScores(Node *newNodePtr, int inNum){
    
      int i, total;                 /* setting int values for use */
      float *valPtr, cumCalc;       /* pointer to help with value iteration */
      struct Cat_Grade *catPtr;     /* pointer to struct member to help with value iteration */
      cumCalc = 0.0;                /* initializing values */
      total = 0;                    /* initializing values */
      
      catPtr = &(newNodePtr->Student.Cat1);
      catPtr = (catPtr + inNum);
      valPtr = &(catPtr->score1);

      catPtr->Cumulative = -1;                          /* Setting Cumulative to -1 */
      
      for(i=0;i<3;i++,valPtr++){
              
              if(*(valPtr) != -1) {

                  cumCalc = cumCalc + *(valPtr);
                  catPtr->Cumulative = cumCalc;        /* Add cumaltive score calculation not including -1   */
                  total++;
                      
                  }
      }
      
      if(total == 0){                                 /* Handles case were -1 exist in full row */
          total = 1;
      }
     
      catPtr->Cumulative = (catPtr->Cumulative) / total;
}
