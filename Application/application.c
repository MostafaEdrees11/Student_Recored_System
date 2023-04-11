#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "..\User\Student\student.h"
#include "..\User\Admin\admin.h"
#include "application.h"


int choose_mode;

int main()
{
	printf("\n");
	printf("***********************************************************\n");
	printf("|               << Welcome To Our Project >>              |\n");
	printf("|               << Student Record System  >>              |\n");
	printf("***********************************************************\n");
	printf("\n\n");
	
	Start_Program();
	
	
	return 0;
}


void Start_Program(void)
{
	//add one admin and two students at when we start the program
	s_admin *head_admin = (s_admin *)malloc(sizeof(s_admin));

	head_admin->m_adminName = "Admin1";
	head_admin->m_adminID = 1000;
	head_admin->m_adminPassword = "1234";
	head_admin->link = NULL;
	
	s_student *head_student = (s_student *)malloc(sizeof(s_student));
	Add_student_record(&head_student,"Student1","Male","1111",95,20,10002056);
	Add_student_record(&head_student,"Student2","Female","2222",97,20,10002057);
	
	do
	{
		printf("\n");
		printf("***********************************************************\n");
		printf("|Admin   Mode               >>                     |Press1|\n");
		printf("|Student Mode               >>                     |Press2|\n");
		printf("***********************************************************\n");
		
		printf("\nYou choose: ");
		scanf("%d",&choose_mode);
		printf("\n");
		
		switch(choose_mode)
		{
			case 1:
			printf("***********************************************************\n");
			printf("|               << Welcome To Admin Mode >>               |\n");
			printf("***********************************************************\n");
			Login(head_admin,head_student);
			break;
			
			case 2:
			printf("***********************************************************\n");
			printf("|               << Welcome To Student Mode >>             |\n");
			printf("***********************************************************\n");
			Login(head_admin,head_student);
			break;
		}
		
		printf("\n");
		printf("Do you want to run again??\n");
		printf("Press y to continue ....");
	}while(getch() == 'y');
	
	
	printf("\n\n");
	printf("***********************************************************\n");
	printf("|                  End of The Program                     |\n");
	printf("***********************************************************\n");
	printf("***********************************************************\n");
	printf("|Company:                                                 |\n");
	printf("|            CAT Reloaded                                 |\n");
	printf("***********************************************************\n");
	printf("|Contributers:                                            |\n");
	printf("|            Eng. Mostafa Edrees                          |\n");
	printf("|            Eng. Samar Ibrahim                           |\n");
	printf("|            Eng. Mariam Elbeshbeeshy                     |\n");
	printf("***********************************************************\n");
	printf("|Supervisor:                                              |\n");
	printf("|            Menna                                        |\n");
	printf("***********************************************************\n");
	printf("|Head:                                                    |\n");
	printf("|            Moshen Yousif                                |\n");
	printf("***********************************************************\n");
}

void Login(s_admin *head_admin, s_student *head_student)
{
	int flag = 0, password_state;
	
	s_admin *ptr_admin = (s_admin *)malloc(sizeof(s_admin));
	ptr_admin = head_admin;
	
	s_student *ptr_student = (s_student *)malloc(sizeof(s_student));
	ptr_student = head_student;
	
	//login for admin
	if(choose_mode == 1)
	{	
		long Entered_ID;
		
		printf("Enter Your ID: ");
		scanf("%ld",&Entered_ID);
		
		while(ptr_admin != NULL)
		{
			if(ptr_admin->m_adminID == Entered_ID)
			{
				password_state = Check_Password(ptr_admin->m_adminPassword);
				if(password_state == 1)
					Admin_Mode();
				flag = 1;
				break;
			}
			ptr_admin = ptr_admin->link;
		}
		
		if(flag == 0)
			printf("ID Doesn't exist.\n");
	}
	else if(choose_mode == 2)  //login for student
	{	
		long Entered_ID;
		
		printf("Enter Your ID: ");
		scanf("%ld",Entered_ID);
		
		while(ptr_student != NULL)
		{
			if(ptr_student->m_id == Entered_ID)
			{
				password_state = Check_Password(ptr_student->m_password);
				if(password_state == 1)
					Student_Mode();
				flag = 1;
				break;
			}
			ptr_student = ptr_student->link;
		}
		
		if(flag == 0)
			printf("ID Doesn't exist.\n");
	}
	
}

int Check_Password(char *password)
{
	int counter, pass_correct_or_not;
	static int num_attempts = 0;
	char Entered_Password[5];
	
	printf("Note: password is only 4 characters.\n");
	printf("Enter Your Password: ");
	for(counter = 0; counter < 4; counter++)
	{
		Entered_Password[counter] = getch();
		printf("*");
	}
	Entered_Password[counter] = '\0';
	
	if(num_attempts < 3)
	{
		if(strcmp(Entered_Password,password) == 0)
			pass_correct_or_not = 1;
		else
		{
			printf("\nWrong Password !!! \n");
			pass_correct_or_not = Check_Password(password);
			num_attempts++;
		}
	}
	else
	{
		pass_correct_or_not = 0;
		printf("\nWrong Password !!! \n");
		printf("You can't try again.\n");
	}
	
	return pass_correct_or_not;
}

void Admin_Mode(void)
{
	int order;

	printf("\n\n");
	
	printf("***********************************************************\n");
	printf("|Add Student Record.                               |Press1|\n");
	printf("|Remove Student Record.                            |Press2|\n");
	printf("|View Student Record.                              |Press3|\n");
	printf("|View All Records.                                 |Press4|\n");
	printf("|Edit Admin Password.                              |Press5|\n");
	printf("|Edit Student Grade.                               |Press6|\n");
	printf("***********************************************************\n");
	
	printf("\nYou choose: ");
	scanf("%d",&order);
	printf("\n");
	
	
	switch(order)
	{
		case 1:
		printf("***********************************************************\n");
		printf("|                  Add Student Record                     |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 2:
		printf("***********************************************************\n");
		printf("|                  Remove Student Record                  |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 3:
		printf("***********************************************************\n");
		printf("|                  View Student Record                    |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 4:
		printf("***********************************************************\n");
		printf("|                  View All Records                       |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 5:
		printf("***********************************************************\n");
		printf("|                  Edit Admin Password                    |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 6:
		printf("***********************************************************\n");
		printf("|                  Edit Student Grade                     |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		default:
		Admin_Mode();
		break;
	}

}

void Student_Mode(void)
{
	int order;
	
	printf("\n\n");
	
	printf("***********************************************************\n");
	printf("|View Your Record.                                 |Press1|\n");
	printf("|Edit Your Password.                               |Press2|\n");
	printf("|Edit Your Name.                                   |Press3|\n");
	printf("***********************************************************\n");
	
	printf("\nYou choose: ");
	scanf("%d",&order);
	printf("\n");
	
	switch(order)
	{
		case 1:
		printf("***********************************************************\n");
		printf("|                  View Your Record                       |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 2:
		printf("***********************************************************\n");
		printf("|                  Edit Your Password                     |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		case 3:
		printf("***********************************************************\n");
		printf("|                  Edit Your Name                         |\n");
		printf("***********************************************************\n");
		printf("\n");
		break;
		
		default:
		Student_Mode();
		break;
	}
}
