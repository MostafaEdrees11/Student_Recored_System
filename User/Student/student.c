#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/*
----------------------------------------------------------------------------------------------
									Function Definition		                	    		 |
----------------------------------------------------------------------------------------------
Name: Edit student name			                                                         |
Parameters: it take two parameters (pointer to head of students linked list, ID of student). |
Return: it returns no thing.                                                                 |
Usage: it is used to edit name of the student that we receive its ID.            |
----------------------------------------------------------------------------------------------
*/
void Edit_student_name(s_student *head_student,long ID){
int flag = 0; /* use flag to check id is exist or not flag=1 this means id is exist ,
              if flag=0 this means id isn't exist*/
char *edit_name ;
	if(head_student == NULL)
		printf("The list is empty.\n");
	else
	{

		while(head_student != NULL)
		{
			if(head_student->m_id == ID)
			{
			    fflush(stdin);
            printf("edit name =");
			gets(edit_name);
			head_student->m_name=edit_name;
				flag = 1;
				break;
			}
			head_student = head_student->link;
		}
		if(flag == 0)
		printf("Wrong ID !!!\n");
	}

}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit student password																	   |
Parameters: it takes parameters (pointer to head of student linked list, student's ID ).		   |
Return: it returns no thing.                                                                   |
Usage: it is used to edit student's password after checking if the id exists.                    |
------------------------------------------------------------------------------------------------
*/

void Edit_Student_Password(s_student* head, long id)
{
	int flag = 0;
	s_student* ptr = head;
	while (ptr != NULL)
	{
		if (ptr->m_id == id)
		{
			printf("Enter the new password:");
			scanf("%s", &ptr->m_password);
			printf("password is edited succesfully\n");
			flag = 1;
			break;
		}
		else
			ptr = ptr->link;
	}
	if (flag == 0)
		printf("Entered ID doesn't exist!\n");
}