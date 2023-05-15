# BY SUBMITTING THIS FILE AS PART OF MY LABE ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CONTENT OF THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
# OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY
# POLICY.

CC = gcc
RM = rm
ARFLAGS = -rf
CCOPTS = -ansi -pedantic
TARGET = lab4main.o
HEADERS = lab4.h

all: lab4main

lab4main: user_interface.o create_student.o delete_node.o insert_node.o option1.o option2.o option3.o option4.o option5.o option6.o option7.o populate_grade.o user_options.o free_nodes.o save_students.o populate_scores.o print_header.o $(TARGET) $(HEADERS)
		$(CC) user_interface.o create_student.o delete_node.o insert_node.o option1.o option2.o option3.o option4.o option5.o option6.o option7.o populate_grade.o user_options.o free_nodes.o save_students.o populate_scores.o print_header.o $(TARGET) -o lab4main

user_interface.o: user_interface.c $(HEADERS)
		$(CC) $(CCOPTS) -c user_interface.c

create_student.o: create_student.c $(HEADERS)
		$(CC) $(CCOPTS) -c create_student.c

delete_node.o: delete_node.c $(HEADERS)
		$(CC) $(CCOPTS) -c delete_node.c

insert_node.o: insert_node.c $(HEADERS)
		$(CC) $(CCOPTS) -c insert_node.c

option1.o: option1.c $(HEADERS)
		$(CC) $(CCOPTS) -c option1.c

option2.o: option2.c $(HEADERS)
		$(CC) $(CCOPTS) -c option2.c

option3.o: option3.c $(HEADERS)
		$(CC) $(CCOPTS) -c option3.c

option4.o: option4.c $(HEADERS)
		$(CC) $(CCOPTS) -c option4.c

option5.o: option5.c $(HEADERS)
		$(CC) $(CCOPTS) -c option5.c

option6.o: option6.c $(HEADERS)
		$(CC) $(CCOPTS) -c option6.c

option7.o: option7.c $(HEADERS)
		$(CC) $(CCOPTS) -c option7.c

populate_grade.o: populate_grade.c $(HEADERS)
		$(CC) $(CCOPTS) -c populate_grade.c

user_options.o: user_options.c $(HEADERS)
		$(CC) $(CCOPTS) -c user_options.c

free_nodes.o: free_nodes.c $(HEADERS)
		$(CC) $(CCOPTS) -c free_nodes.c

save_students.o: save_students.c $(HEADERS)
		$(CC) $(CCOPTS) -c save_students.c

populate_scores.o: populate_scores.c $(HEADERS)
		$(CC) $(CCOPTS) -c populate_scores.c

print_header.o: print_header.c $(HEADERS)
		$(CC) $(CCOPTS) -c print_header.c

clean:
		$(RM) $(ARFLAGS) *.o $(TARGET) 