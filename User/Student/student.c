#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "..\..\System\system.h"

s_student *head_student;

void add_student_at_start(void)
{
	//student1
	head_student = (s_student *)malloc(sizeof(s_student));
	head_student->m_name = "Student1";
	head_student->m_gender = "Male";
	head_student->m_password = "1111";
	head_student->m_grade = 95;
	head_student->m_age = 20; 
	head_student->m_id = 10002056;
	head_student->link = NULL;
	
	//student2
	s_student *new_student = (s_student *)malloc(sizeof(s_student));
	new_student->m_name = "Student2";
	new_student->m_gender = "Female";
	new_student->m_password = "2222";
	new_student->m_grade = 97;
	new_student->m_age = 20; 
	new_student->m_id = 10002057;
	new_student->link = NULL;
	head_student->link = new_student;
}

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
char * Edit_student_name(s_student *head_student,long ID)
{
	int flag = Not_Exist; 
	char *edit_name ;
	
	if(head_student == NULL)
	{
		printf("***********************************************************\n");
		printf("|                   The list is empty.                    |\n");
		printf("***********************************************************\n");
	}
	else
	{

		while(head_student != NULL)
		{
			if(head_student->m_id == ID)
			{
			    fflush(stdin);
				printf("Enter New Name: ");
				//gets(edit_name);
				fflush(stdin);
				fgets(edit_name, 20, stdin);
				edit_name[strcspn(edit_name, "\n")] = '\0';
				head_student->m_name = edit_name;
				flag = Exist;
				
				printf("\n");
				printf("***********************************************************\n");
				printf("|             Edited Student Name Succesfully             |\n");
				printf("***********************************************************\n");
				break;
			}
			head_student = head_student->link;
		}
		if(flag == Not_Exist)
		{
			printf("\n");
			printf("***********************************************************\n");
			printf("|            The entered ID already exists!               |\n");
			printf("***********************************************************\n");
		}
	}
	
	return edit_name;
}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit student password																	   |
Parameters: it takes parameters (pointer to head of student linked list, student's ID ).		|
Return: it returns password.                                                                   |
Usage: it is used to edit student's password after checking if the id exists.                    |
------------------------------------------------------------------------------------------------
*/

char* Edit_Student_Password(s_student *head,long id)
{
	int flag = Not_Exist;
	char *new_pass;
	

	if(head == NULL)
	{
		printf("***********************************************************\n");
		printf("|                   The list is empty.                    |\n");
		printf("***********************************************************\n");
		
	}
	else
	{

		while(head != NULL)
		{
			if(head->m_id == id)
			{
				printf("-----------------------------------------------------------\n");
				printf("|          Note: password is only 4 characters.           |\n");
				printf("-----------------------------------------------------------\n");
				printf("Enter the New Password: ");
				fflush(stdin);
				fgets(new_pass, 5, stdin);
				new_pass[strcspn(new_pass, "\n")] = '\0';
				head->m_password = new_pass;
				
				flag = Exist;
				
				printf("\n");
				printf("***********************************************************\n");
				printf("|               Password Edited Succesfully               |\n");
				printf("***********************************************************\n");
				break;
			}
			head = head->link;
		}
		
		if(flag == Not_Exist)
		{
			printf("***********************************************************\n");
            printf("|            The entered ID already exists!               |\n");
			printf("***********************************************************\n");
		}
	}
	return new_pass;
}