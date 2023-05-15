/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File populate_grade.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: populateGrade
* -------------------------
* populateGrade - Calculates grade for Current_Grade & Final_Grade based upon gradeType
*
* Parameter 1: newNodePtr* The Node Address location
* Parameter 2: gradeType Determains if final grade or Current Grade is being calculated.
* Value is determined by either 100 or 0 to replace -1.
* ...
*
* returns: float - Returns calculated results
*
*/

float populateGrade(Node *newNodePtr, int gradeType){
    
    int i;                                         /* setting int values for use */
    float *cumVal, total;                          /* values to help store for calucaltions */
    float percent[4] = {0.15, 0.30, 0.20, 0.35};   /* grade catagory percentage values */
    struct Cat_Grade *cumCalc;                     /* pointer to struct member to help with value iteration */
    total = 0.0;                                   /* setting initial value */
    
    cumCalc = &(newNodePtr->Student.Cat1);

    for (i=0; i < 4; i++)
    {
        if(cumCalc->Cumulative != -1){
        
            total = total + (cumCalc->Cumulative * percent[i]);
        
        } else {
            
               total = total + (gradeType * percent[i]);    /* If cumalative = -1, use 100 or use 0 if stated */
        }
        cumCalc++;
    }
    
    return total;
    
}

