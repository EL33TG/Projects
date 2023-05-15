/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File user_options.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: userOptions
* -------------------------
* userOptions - Print Student Scores for All Students - (Called from user_interface.c)
*
* ...
*
* returns: int - user selection is returned
*
*/
int userOptions(){
    
    int option;        /* setting int values for use, return value */
    
    printf("\n");
    printf("Please enter an option between 1 and 10:\n");
    printf("1)  Print Student Scores by Student ID\n");
    printf("2)  Print Student Scores by Last Name\n");
    printf("3)  Print Student Scores for All Students\n");
    printf("4)  Recalculate Student Scores for a Single Student ID\n");
    printf("5)  Recalculate All Student Scores\n");
    printf("6)  Insert a score for a specific Student ID\n");
    printf("7)  Calculate Final Grades\n");
    printf("8)  Add a new student\n");
    printf("9)  Delete a student\n");
    printf("10) Exit Program\n");

    do
    {
        printf("\nPlease choose an option between 1-10: ");
        scanf("%d", &option);
        getchar();
} while ((option < 1 || option > 10));
    
    
    return option;
}
