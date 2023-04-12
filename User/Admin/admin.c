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
			
			printf("\n");
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
					
					printf("\n");
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
			printf("|              The entered ID is wrong!!!                 |\n");
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
    char name[100], gender[100], password[100];
    int grade, age;
    long id;

    printf("Enter Name: ");
	fflush(stdin);
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter ID: ");
    scanf("%ld", &id);

    printf("Enter Gender: ");
	fflush(stdin);
    fgets(gender, 100, stdin);
    gender[strcspn(gender, "\n")] = '\0';

    printf("Enter Password: ");
	fflush(stdin);
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';

    printf("Enter Grade: ");
    scanf("%d", &grade);

    printf("Enter Age: ");
    scanf("%d", &age);

    // Allocate memory for the new student record
    s_student* temp = (s_student*)malloc(sizeof(s_student));
    if(temp == NULL)
	{
        printf("Error: Failed to allocate memory\n");
        return;
    }

    // Copy the input strings to the newly allocated memory
    temp->m_name = strdup(name);
    temp->m_gender = strdup(gender);
    temp->m_password = strdup(password);
    temp->m_grade = grade;
    temp->m_age = age;
    temp->m_id = id;
    temp->link = NULL;

    // Check if the new record's ID is unique
    s_student* ptr = *head;
    while(ptr != NULL)
	{
        if(ptr->m_id == temp->m_id)
		{
			printf("***********************************************************\n");
            printf("|            The entered ID already exists!               |\n");
			printf("***********************************************************\n");
            free(temp->m_name);
            free(temp->m_gender);
            free(temp->m_password);
            free(temp);
            return;
        }
        ptr = ptr->link;
    }

    // Add the new record to the linked list
    if (*head == NULL)
	{
        *head = temp;
		printf("***********************************************************\n");
        printf("|           Student record added successfully             |\n");
		printf("***********************************************************\n");
    } 
	else
	{
        ptr = *head;
        while(ptr->link != NULL)
		{
            ptr = ptr->link;
        }
        ptr->link = temp;
        printf("***********************************************************\n");
        printf("|           Student record added successfully             |\n");
		printf("***********************************************************\n");
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


// void Edit_Admin_Password(s_admin *head,long id)
// {
    // int flag = 0, counter;
    // //char password[5],confirm_password[5];
    // char password[5];

    // //s_adminptr = head;

    // while (head != NULL)
    // {
        // if (head->m_adminID == id)
        // {
            // flag = 1;
            // printf("Note: password is only 4 characters.\n");
            // printf("Enter the new password:");
            // for(counter = 0; counter < 4; counter++)
            // {
                // fflush(stdin);
                // password[counter] = getch();
                // printf("");
            // }
            // password[counter] = '\0';

            // head->m_adminPassword = password;
            // printf("\n");
            // printf("**\n");
            // printf("|              password is updated succesfully            |\n");
            // printf("**\n");
            // printf("%s",head->m_adminPassword);
            // flag = 1;
            // break;
        // }
        // head= head->link;
    // }
    // if(flag == 0)
        // {
            // printf("\n");
            // printf("**\n");
            // printf("|                Entered ID doesn't exist!                |\n");
            // printf("**\n");
        // }
// }


s_admin * Edit_Admin_Password(s_admin *head,long id)        
{
	int flag = 0, counter;
	char password[5];
	
	s_admin *ptr = head;
	if(ptr->m_adminID == id)
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
		
		head->m_adminPassword = password;
		printf("\nafter: %s\n",head->m_adminPassword);
		printf("%s\n",password);
	}
	else
	{
		while(ptr->link != NULL)
		{
			if(ptr->m_adminID == id)
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
				
				ptr->m_adminPassword = password;
				break;
			}
			ptr = ptr->link;
		}
	}
	
	if (flag == 0)
		printf("Entered ID doesn't exist!\n");
	
	return ptr;
}


/*while (head != NULL)
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
			
			head->m_adminPassword = password;
			
			/*printf("\nConfirm the password:");
			for(counter = 0; counter < 4; counter++)
			{
				fflush(stdin);
				confirm_password[counter] = getch();
				printf("*");
			}
			confirm_password[counter] = '\0';*/
			
			// printf("\n%s\n",password);
			// printf("\n%s\n",head->m_adminPassword);
			// printf("%s\n",confirm_password);
			
			/*if(strcmp(password,confirm_password) == 0)
			{
				(*ptr)->m_adminPassword = password;
				printf("\n");
				printf("***********************************************************\n");
				printf("|             Password is edited succesfully              |\n");
				printf("***********************************************************\n");
				printf("\n");
				printf("%s\n",password);
				printf("%s\n",confirm_password);
				printf("%s\n",(*ptr)->m_adminPassword);
				break;
			}
			else
			{
				printf("\n");
				printf("***********************************************************\n");
				printf("|          The two password aren't equivalent.            |\n");
				printf("***********************************************************\n");
				printf("\n");
				Edit_Admin_Password(id);
				break;
			}
		}
		head = head->link;
	}*/