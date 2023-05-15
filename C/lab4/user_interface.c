/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File user_interface.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: option5
* -------------------------
* user_interface - The user interface file where all functions are initially called
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char* The Filename 1 name
* Parameter 3: char* The Filename 1 name
* ...
*
* returns: nothing
*
*/
void user_interface(Node **list_head, char *filename1, char *filename2){

    FILE *readTo;                /* Store open/read file*/
    int userChoice;              /* setting int values for use, stored user option information */
    char categories[4][40];      /* stored the initial 4 categories */
    Node *newNodePtr = NULL;     /* creates the initial new node pointer */


    if((readTo = fopen(filename1, "r"))){           /* opens files stream */
        
        fscanf(readTo,"%s%s%s%s\n", categories[0],categories[1],categories[2],categories[3]);      /* Store 4 initial category names */
        

        while(!feof(readTo)){                                   /* Do until end of file */
    
            newNodePtr = create_student(list_head, readTo);     /* Populate students */
            insert_node(list_head, newNodePtr);                 /* Insert files into linked list in Ascending order */

        }
        fclose(readTo);                                          /* Finished reading file into Linked List */
        
        newNodePtr = *list_head;                         /* Only this was missing from submission - because I am passing this value over to                                                       function, it needs to be reset to mimic *list_head or else it will point to wrong value */
            
        
        do{
    
       userChoice = userOptions();                               /* Get user input choice */
       executeUserOption(newNodePtr,list_head,userChoice,filename2, categories);   /* Passing over choice to function pointer */
   
        } while (userChoice != 10);                             /* exit program when value 10 reached */
    }
 
}


/*
* Function: executeUserOption
* -------------------------
* executeUserOption - The switch/case hub where all options and actions to execute are called
*
* Parameter 1: Node* The Node Address location
* Parameter 2: Node** The listHead Address location
* Parameter 3: int Users selection
* Parameter 4: char* The Filename 2 name
* Parameter 5: char** The 4 saved categories
* ...
*
* returns: nothing
*
*/
void executeUserOption(Node *newNodePtr, Node **list_head, int userChoice, char *filename2, char categories[][40]){
    
    void (*fp[7])(Node *, char [][40]) = {option1, option2, option3, option4, option5, option6, option7};   /* Setting up variable for function pointer */
    int studentID;
    
    switch (userChoice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            (fp[userChoice-1])(newNodePtr, categories);                             /* Function pointer callout */
            break;
        case 8:
            newNodePtr = create_student(list_head, NULL);                           /* manually create student & insert into linked list */
            insert_node(list_head, newNodePtr);
           break;
        case 9:                                                                     /* Delete node by student ID */
            
            printf("Please enter student ID # to delete: ");
            scanf("%d", &studentID);
            delete_node(list_head, studentID);
            break;
        case 10:

            saveStudentsToFile(list_head, filename2, categories);                   /* saving all data to output filename, freeing memory & ending program*/
            freeAllNodes(list_head);
            break;
            
        default:
            break;
    }
}
