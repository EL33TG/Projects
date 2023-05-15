/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File main.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: main
* -------------------------
* main - Main starting point of the program. Calls out to the user_interface.
*
* Parameter 1: int initial command line index
* Parameter 2: char** initial command line arguments
* ...
*
* returns: int ( success=0 or not successful=1 )
*
*/

int main(int argc, char **argv){

    char *filename1 = argv[1];  /* Setting incoming filename */
    char *filename2 = argv[2];  /* Setting incoming filename */
    Node *list_head = NULL;     /* Creating list head pointer */
    
    printf("\n");
    user_interface(&list_head, filename1,filename2); /* main callout to user_interface where all the magic happens :) */
    printf("\n");
    
    return (0);
    
}
