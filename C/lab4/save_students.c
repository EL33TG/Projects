/* BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
** OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
** POLICY.
*/

/*
* File save_students.c
*
* Author: Brenden Boswell
*
*
* Including lab.h header file
*/
#include "lab4.h"

/*
* Function: saveStudentsToFile
* -------------------------
* saveStudentsToFile - saves student data to file given @ start of program
*
* Parameter 1: Node* The listeHead Address location
* Parameter 2: char* The filename to save
* Parameter 3: char** The categories Address location
* ...
*
* returns: nothing
*
*/
void saveStudentsToFile(Node **list_head, char *filename2, char categories[][40]){
    
        int count;                        /* setting int values for use */
        FILE *writeTo;                    /* opening up initial stream */
        Node *traversePtr = *list_head;   /* setting new head to pointer to original list address */
        count = 0;                        /* Initializing all values to 0 */
        
        
        if((writeTo = fopen(filename2, "w+"))){
            fprintf(writeTo, "%s %s %s %s\n", categories[0],categories[1],categories[2],categories[3]);
            
            while (traversePtr != NULL) {         /* determine list is not empty */
            
            fprintf(writeTo, "%s", traversePtr->Student.student_name);
            fprintf(writeTo, "%d\n", traversePtr->Student.student_ID);
            fprintf(writeTo, "%.2f\t%.2f\t%.2f\n", traversePtr->Student.Cat1.score1, traversePtr->Student.Cat1.score2, traversePtr->Student.Cat1.score3);
            fprintf(writeTo, "%.2f\t%.2f\t%.2f\n", traversePtr->Student.Cat2.score1, traversePtr->Student.Cat2.score2, traversePtr->Student.Cat2.score3);
            fprintf(writeTo, "%.2f\t%.2f\t%.2f\n", traversePtr->Student.Cat3.score1, traversePtr->Student.Cat3.score2, traversePtr->Student.Cat3.score3);
            fprintf(writeTo, "%.2f\t%.2f\t%.2f\n", traversePtr->Student.Cat4.score1, traversePtr->Student.Cat4.score2, traversePtr->Student.Cat4.score3);
                
                count++;
                traversePtr = traversePtr->next;
        
    }
                printf("\nSaving Data......\n");
                printf("There were a total of %d records written to [%s]\n", count, filename2);
           
            fclose(writeTo);
    } else {
         
        
           printf("\nError: no filename provided.\n");
    }
          

}
