/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File delete_node.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"
/*
* Function: delete_node
* -------------------------
* delete_node - Iterate through linked list and delete Node by StudentID
*
* Parameter 1: Node* The Node Address location
* Parameter 2: int The studentId to find node to be deleted
* ...
*
* returns: nothing
*
*/
void delete_node(Node **list_headAdr, int studentID){
    
    Node *traversePtr = *list_headAdr;      /* setting new head to pointer to original list address */
    
    
    if(traversePtr == NULL){                /* if nothing to find, specify */
        printf("Null");
    }
    else if (traversePtr->Student.student_ID == studentID){
        
        *list_headAdr = traversePtr->next;  /* Point main to next node in list */
        free(traversePtr);                  /* Free node when found */
        
        /* ^ At beginning of list */
        
    } else {
        
        Node *priorNodePtr = traversePtr;     /* create preceeding node */
        traversePtr = traversePtr->next;
        
        while((traversePtr != NULL) &&
            (traversePtr->Student.student_ID !=studentID)){
            
            priorNodePtr = traversePtr;
            traversePtr = traversePtr->next;
        }
        if(traversePtr == NULL){
            printf("\n Error: Student ID number %i was not found in the list\n", studentID);
        
        } else {
            
            priorNodePtr->next = traversePtr->next;
            free(traversePtr);                  /* Free node when found */
        }
    }
}
