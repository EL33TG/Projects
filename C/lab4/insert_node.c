/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File insert_node.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: insert_node
* -------------------------
* insert_node - Inserts node into linked list
*
* Parameter 1: Node** The Node Address location
* Parameter 2: Mode* The NEW Node Address location to be inserted
* ...
*
* returns: nothing
*
*/
void insert_node(Node **list_headAdr, Node *newNodePtr){
    
 Node *traversePtr = *list_headAdr;          /* set traverse node to original node address location */
         
    if (traversePtr == NULL){                /* if no node exits, insert here */
             newNodePtr->next = NULL;
             *list_headAdr = newNodePtr;     /* INSERT NODE */
        
     } else if(newNodePtr->Student.student_ID < traversePtr->Student.student_ID){   /* if studentID of new is < old, insert here */
         
        newNodePtr->next = traversePtr;     /* INSERT NODE */
        *list_headAdr = newNodePtr;         /* INSERT NODE */
         
     }else{
         
         Node *priorNodePtr = traversePtr;
         traversePtr = traversePtr->next;
         
         while((traversePtr != NULL) && (newNodePtr->Student.student_ID > traversePtr->Student.student_ID)){    /* if studentID of new is > old, insert here */
             
             priorNodePtr = traversePtr;
             traversePtr = traversePtr->next;
         }
         
         newNodePtr->next = traversePtr;
         priorNodePtr->next = newNodePtr;
     
     }

}
