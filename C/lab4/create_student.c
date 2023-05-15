/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File create_student.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"
/*
* Function: create_student
* -------------------------
* create_student - Creates student node and populates data for inser preperation
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: FILE* The file streamer to read/write files, if NULL -> triggers manual input of student
* ...
*
* returns: Node* creates initial & additional student nodes & populates data before node insert
*
*/

Node* create_student(Node **list_head, FILE *readTo){
   
    int i, j;                       /* setting int values for use */
    const int CURRENT = 100;        /* setting constant variable for calculation (100 or 0) */
    Node *newNodePtr;               /* creating new node pointer holder */
     newNodePtr = *list_head;      /* setting new head to pointer to original list address */
        
    if ((newNodePtr = malloc(sizeof(Node))) != NULL){                   /* alloc memory for node(create space) */
    
        if (readTo != NULL){                                            /* check for successful memory allocation */
    
            fgets((newNodePtr->Student.student_name), 41, readTo);      /* Read entire line into name */
            fscanf(readTo,"%d", &(newNodePtr->Student.student_ID));     /* Read value into studentID */
            newNodePtr->Student.Final_Grade = -1;                       /* initialize Final Grade to -1 */
    
    for (i =0; i<4; i++){                                               /* Populate grades & Categories (loop) */
        populateCategories(newNodePtr, i, readTo);
        populateScores(newNodePtr, i);
    }

            
        } else {  /* if triggered/called, creating student manually below NULL readTo variable determines this */
          
            printf("Enter your student information manually\n ");
            printf("\n ");
            
            printf("Enter student name:\n ");
            fgets((newNodePtr->Student.student_name), 41, stdin);
            
            printf("Enter student ID: ");
            scanf("%d", &(newNodePtr->Student.student_ID));
       
            
            for (j=0;j<4;j++){
                
                printf("Enter student scores for Category %d seperated by space, (-1 to leave blank):\n ", (j+1));
                populateCategories(newNodePtr, j, NULL);
            }
      
        }
      newNodePtr->Student.Current_Grade = populateGrade(newNodePtr, CURRENT);         /* Populate Current Grade */

        
        
    } else {
        
        printf("Error allocating memory for Node ");                                   /* memory allocation error message */
    }
    
    return newNodePtr;
}


/*
* Function: populateCategories
* -------------------------
* populateCategories - Print Student Scores for All Students - (Called from user_interface.c)
*
* Parameter 1: Node* The Node Address location
* Parameter 2: FILE* The file streamer to read/write files, if NULL -> triggers manual input of student
* ...
*
* returns: Node* creates initial & additional student nodes & populates data before node insert
*
*/
void populateCategories(Node *newNodePtr, int inNum, FILE *readTo){
    
    int i;
    float *valPtr;
    struct Cat_Grade *catPtr;
    
    catPtr = &(newNodePtr->Student.Cat1);       /* setting pointer to Cat struct member to allow incrementation */
    catPtr = (catPtr + inNum);
    valPtr = &(catPtr->score1);                 /* setting pointer to float struct member to allow incrementation */
    
    for(i=0;i<3;i++,valPtr++){
            
        if (readTo != NULL){                    /* if NULL - file called for manual input, read from inpute line */
            fscanf(readTo,"%f\n", valPtr);
        } else {
            scanf("%f", valPtr);
        
        }
    }
}
