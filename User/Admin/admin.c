#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include "admin.h"
#include "..\..\System\system.h"
#include "..\Student\student.h"
#include "..\..\Application\application.h"

s_admin *head_admin;

void add_admin_at_start(void)
{
	head_admin = (s_admin *)malloc(sizeof(s_admin));
	head_admin->m_adminName = "Admin1";
	head_admin->m_adminID = 1000;
	head_admin->m_adminPassword = "1234";
	head_admin->link = NULL;
}

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

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Remove student record		                                                               |
Parameters: it take two parameters (pointer to pointer to head of students linked list, ID of student ).                  |
Return: it returns no thing.                                                                   |
Usage: it is used to Remove student record by entered the student ID . |
------------------------------------------------------------------------------------------------
*/
void Remove_student_record (s_student **head_student,long ID)
{
	int flag=0;    //use to check id is correct or not, flag =0 that means id is wrong,flag=1 id is correct
	s_student *current=*head_student;   //pointer point to head of students ,use it to free the memory
	s_student *previous= *head_student; //pointer point to head of students 

	if (*head_student==NULL)
	{
		printf("list is empty \n");
	}
	else
	{
		
		/*if condition to  remove student record of head student (first)
		check if ID is id of the head student(first student) then remove  by
		current points to head that want to remove ,then  head_student point to second
		then free current 
		else check the rest record
		*/
		if((*head_student)->m_id==ID)
		{
			current = *head_student;  
			*head_student = current->link;
			free(current);    // free the memory
			current=NULL;
			
			printf("***********************************************************\n");
			printf("|              Removed Student succesfully                |\n");
			printf("***********************************************************\n");
			flag=1;
		}
		else
		{
			while(previous->link != NULL)
			{
				if(previous->link->m_id ==ID) //if  previous->link->m_id==ID ,we need to delete the previous->link
		        {
					current = previous->link;       //current point to the student record that has this id( this id of student want to remove) 
					previous->link = current->link; //previous now  doesn't point to this student record(this id of student want to remove) but point to after this ,
			                               // now node(student record of this id) will be disconnceted from the linked list
					free(current);           //free the memory
					current = NULL;
				
					printf("***********************************************************\n");
					printf("|              Removed Student succesfully                |\n");
					printf("***********************************************************\n");
					flag=1;
					break;
				}
				//Otherwise, move the previous node and proceed
				else
                  previous = previous->link;
			}
		}

		if(flag==0)
		{
			printf("\n");
			printf("***********************************************************\n");
			printf("|            The entered ID already exists!               |\n");
			printf("***********************************************************\n");
		}
	}
}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit student grade		                                                               |
Parameters: it take two parameters ( pointer to head of students linked list, ID of student ).                  |
Return: it returns no thing.                                                                   |
Usage: it is used to Edit student grade by entered the student ID . |
------------------------------------------------------------------------------------------------
*/
void Edit_student_grade(s_student *head_student,long ID){
int flag = 0; /* use flag to check id is exist or not flag=1 this means id is exist ,
              if flag=0 this means id isn't exist*/
int new_grade;
	if(head_student == NULL){printf("The list is empty.\n");}	
	else
	{

		while(head_student != NULL)
		{
			if(head_student->m_id == ID)
			{
				printf("\nEnter the new grade: ");
				scanf("%d",&new_grade);
				head_student->m_grade=new_grade;
				printf("\n");
				printf("***********************************************************\n");
				printf("|              Grade is updated succesfully               |\n");
				printf("***********************************************************\n");
				flag = 1;
				break;
			}
			head_student = head_student->link;
		}
		if(flag == 0)
		{
			printf("\n");
			printf("***********************************************************\n");
			printf("|                Entered ID doesn't exist!                |\n");
			printf("***********************************************************\n");
		}
	}

}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Add student record		                                                               |
Parameters: it takes parameters (pointer to head of students linked list, student data ).      |
Return: it returns no thing.                                                                   |
Usage: it is used to add student record by entered the student data .                          |
------------------------------------------------------------------------------------------------
*/
void Add_student_record(s_student** head)
{
	char *name, *gender, *password;
	int grade, age;
	long id;
	
	printf("Enter Name: ");
	fflush(stdin); fflush(stdout);
	scanf("%[^\n]%*c",&name); 
	//gets(name);
	
	printf("Enter ID: ");
	fflush(stdin);
	scanf("%ld",&id);
	
	printf("Enter Gender: ");
	fflush(stdin);
	scanf("%[^\n]%*c",&gender);
	//gets(gender);
	
	printf("Enter Password: ");
	fflush(stdin);
	scanf("%[^\n]%*c",&password);
	//gets(password);
	
	printf("Enter Grade: ");
	fflush(stdin);
	scanf("%d",&grade);
	
	printf("Enter Age: ");
	fflush(stdin);
	scanf("%d",&age);
	
	int flag = 1;         //used to indicate whether the id is unique or not
	s_student* ptr = *head;


	if (ptr == NULL)
	{
		ptr->m_name = name;
		ptr->m_gender = gender;
		ptr->m_password = password;
		ptr->m_grade = grade;
		ptr->m_age = age;
		ptr->m_id = id;
		ptr->link = NULL;

		printf("\n");
		printf("***********************************************************\n");
		printf("|            Student record added succesfully             |\n");
		printf("***********************************************************\n");
	}
	else
	{
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
			if (ptr->m_id == id)
				flag = 0;
		}

		if (flag)
		{
			s_student* temp = (s_student*)malloc(sizeof(s_student));
			temp->m_name = name;
			temp->m_gender = gender;
			temp->m_password = password;
			temp->m_grade = grade;
			temp->m_age = age;
			temp->m_id = id;
			temp->link = NULL;
			ptr->link = temp;
			
			printf("\n");
			printf("***********************************************************\n");
			printf("|            Student record added succesfully             |\n");
			printf("***********************************************************\n");
		}
		else
		{
			printf("\n");
			printf("***********************************************************\n");
			printf("|            The entered ID already exists!               |\n");
			printf("***********************************************************\n");
		}
	}
}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit admin password																	   |
Parameters: it takes parameters (pointer to head of admins linked list, admin's ID ).		   |
Return: it returns no thing.                                                                   |
Usage: it is used to edit admin's password after checking if the id exists.                    |
------------------------------------------------------------------------------------------------
*/

void Edit_Admin_Password(s_admin* head, long id)        
{
	int flag = 0, counter;
	char password[5],confirm_password[5];
	
	while (head != NULL)
	{
		if (head->m_adminID == id)
		{
			flag = 1;
			printf("Note: password is only 4 characters.\n");
			printf("Enter the new password:");
			for(counter = 0; counter < 4; counter++)
			{
				fflush(stdin);
				password[counter] = getch();
				printf("*");
			}
			password[counter] = '\0';
			
			printf("\nConfirm the password:");
			for(counter = 0; counter < 4; counter++)
			{
				fflush(stdin);
				confirm_password[counter] = getch();
				printf("*");
			}
			confirm_password[counter] = '\0';
			
			if(strcmp(password,confirm_password) == 0)
			{
				head->m_adminPassword = password;
				printf("\n");
				printf("***********************************************************\n");
				printf("|             Password is edited succesfully              |\n");
				printf("***********************************************************\n");
				printf("\n");
				break;
			}
			else
			{
				printf("\n");
				printf("***********************************************************\n");
				printf("|          The two password aren't equivalent.            |\n");
				printf("***********************************************************\n");
				printf("\n");
				Edit_Admin_Password(head,id);
				break;
			}
		}
		else
			head = head->link;
	}
	if (flag == 0)
		printf("Entered ID doesn't exist!\n");
}