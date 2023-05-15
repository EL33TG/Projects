/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File option7.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: option7
* -------------------------
* Option7 - Calculate Final Grades - (Called from user_interface.c)
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char** The categories Address location
* ...
*
* returns: nothing
*
*/
void option7(Node *list_head, char categories[][40]){
    const int CURRENT = 0;              /* constant used to determine grade calculation (0 or 100) */
    Node *traversePtr = list_head;      /* pointing new Node to old Node */
    
    
    while(traversePtr != NULL)          /* Iterating through nodes until NUL is reached */
    {
        if (traversePtr != NULL){
            
        traversePtr->Student.Final_Grade = populateGrade(traversePtr, CURRENT);          /* Storing calculated final grade, from function */
        traversePtr = traversePtr->next;
    }
}
    option5(list_head, categories);       /* Calling option 5 to print all students */
}
