#include <admin.h>
#include "system.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: View_all_records			                                                               |
Parameters: it take one parameters (pointer to head of students linked list).                  |
Return: it returns no thing.                                                                   |
Usage: it is used to print the all information of the students that exists in the linked list. |
------------------------------------------------------------------------------------------------
*/
void View_all_records(s_student *head_student)
{
	/*
	counter variable is used to count number of the students
	total_grade is used to calculate the total grade of all students
	average_grade is used to calculate the average grade of all students
	*/
	int counter = 0, total_grade = 0, average_grade;
	
	if(head_student == NULL)
		printf("The list is empty.\n");
	else
	{
		while(head_student != NULL)
		{
			printf("\n");
			printf("-------------------------------------------------\n");
			printf("|Student Number | "); print_int(++counter);
			printf("-------------------------------------------------\n");
			printf("|ID             | "); print_int(head_student->m_id);
			printf("|Name           | "); print_string(head_student->m_name,strlen(head_student->m_name));
			printf("|Password       | "); print_string(head_student->m_password,strlen(head_student->m_password));
			printf("|Gender         | "); print_string(head_student->m_gender,strlen(head_student->m_gender));
			printf("|Age            | "); print_int(head_student->m_age);
			printf("|Total Grade    | "); print_int(head_student->m_grade);
			printf("-------------------------------------------------\n");
			
			total_grade += head_student->m_grade;
			
			head_student = head_student->link;
		}
		
		average_grade = total_grade / counter;
		
		printf("\n");
		printf("-------------------------------------------------\n");
		printf("|Total Grade    | "); print_int(total_grade);
		printf("|Average Gradde | "); print_int(average_grade);
		printf("-------------------------------------------------\n");
	}
}
