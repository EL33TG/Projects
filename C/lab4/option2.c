/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File option2.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: option2
* -------------------------
* Option2 - Print Student Scores by Last Name - (Called from user_interface.c)
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char** The categories Address location
* ...
*
* returns: nothing
*
*/

void option2(Node *list_head, char categories[][40]){
    
    int i,j,inputLength,flag;            /* setting int values for use */
    char *firstWord, *secondWord, *line, holder[41], lastName[40], delimiter[] = " ";  /* setting char members and initializing start valuess */
    
    struct Cat_Grade *cat;              /* pointer to struct member to help with value iteration */
    float *score;                       /* pointer to help with value iteration */
    Node *traversePtr = list_head;      /* setting new head to pointer to original list address */
    flag = 0;                           /* setting flag for loop position indicator */
    
    printf("Enter the Student Last Name: ");
    scanf("%s", lastName);
    printf("Hunting for %s\n", lastName);
 
    printHeader(categories);             /* Print initial header output */
    
        while(traversePtr != NULL && flag != 1)
        {
            strcpy(holder,traversePtr->Student.student_name);    /* Copy string to protect data */
            inputLength = strlen(holder);
            
            if ((line = malloc(inputLength*sizeof(char))) != NULL) {
            
           firstWord = strtok(holder, delimiter);           /* Paring first string in set */
           secondWord = strtok(NULL, delimiter);            /* Paring next string in set */
           
        firstWord[strlen(lastName)] = '\0';              /* NULL terminate string */
           secondWord[strlen(lastName)] = '\0';             /* NULL terminate string */

            if(strcmp(secondWord, lastName) == 0){

              /* printing initial non-repeated values (student name & studentID) */
                
                printf("\n%s\t\t%d\t\t \n", traversePtr->Student.student_name,traversePtr->Student.student_ID);
                printf("\t\t\t\t");
                cat = &(traversePtr->Student.Cat1);
                score = &(cat->score1);
                
                
                for (i=0; i<6;i++){
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
                
            } else {
                printf("Error: Could not allocate memory!\n");
            }
        }

}
