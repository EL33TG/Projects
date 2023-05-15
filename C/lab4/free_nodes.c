/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File free_nodes.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"
/*
* Function: freeAllNodes
* -------------------------
* freeAllNodes - Iterates and frees every node allocated in memory, on linked list
*
* Parameter 1: Node** The Node Address location
* ...
*
* returns: nothing
*
*/
void freeAllNodes(Node **list_head){
    
    Node *traverse = *list_head;     /* setting 1st new head to pointer to original list address */
    Node *restOfList = *list_head;   /* setting 2nd new head to pointer to original list address */
        
        while (restOfList != NULL) {         /* determine list is not empty */
            restOfList = restOfList->next;
            
            free(traverse);                  /* free allocated node from memory */
            
            traverse = restOfList;
        }
}
