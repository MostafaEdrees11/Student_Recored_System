#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "..\User\Student\student.h"
#include "..\User\Admin\admin.h"
#include "..\System\system.h"
#include "application.h"

extern s_student *head_student;
extern s_admin *head_admin;

int choose_mode;

int main()
{
	//add one admin and two students at when we start the program
	add_admin_at_start();
	add_student_at_start();
	
	Start_Program();
	
	
	return 0;
}


void Start_Program(void)
{	
	do
	{
		printf("\n");
		printf("***********************************************************\n");
		printf("|               << Welcome To Our Project >>              |\n");
		printf("|               << Student Record System  >>              |\n");
		printf("***********************************************************\n");
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
			Login();
			break;
			
			case 2:
			printf("***********************************************************\n");
			printf("|               << Welcome To Student Mode >>             |\n");
			printf("***********************************************************\n");
			Login();
			break;
			
			default:
			printf("***********************************************************\n");
			printf("|                You Enter Wrong Choose.                  |\n");
			printf("***********************************************************\n");
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

void Login(void)
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
					Admin_Mode(ptr_admin->m_adminID);
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
		scanf("%ld",&Entered_ID);
		
		while(ptr_student != NULL)
		{
			if(ptr_student->m_id == Entered_ID)
			{
				password_state = Check_Password(ptr_student->m_password);
				if(password_state == 1)
					Student_Mode(ptr_student->m_id);
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
	
	printf("\nNote: password is only 4 characters.\n");
	printf("Enter Your Password: ");
	for(counter = 0; counter < 4; counter++)
	{
		Entered_Password[counter] = getch();
		printf("*");
	}
	Entered_Password[counter] = '\0';
	
	if(num_attempts < 2)
	{
		if(strcmp(Entered_Password,password) == 0)
		{
			num_attempts = 0;
			pass_correct_or_not = 1;
		}
		else
		{
			printf("\n\n");
			printf("***********************************************************\n");
			printf("|                   Wrong Password !!!                    |\n");
			printf("***********************************************************\n");
			num_attempts++;
			pass_correct_or_not = Check_Password(password);
		}
	}
	else
	{
		pass_correct_or_not = 0;
		num_attempts = 0;
		printf("\n\n");
		printf("***********************************************************\n");
		printf("|                   Wrong Password !!!                    |\n");
		printf("|                   You can't try again !!!               |\n");
		printf("***********************************************************\n");
		printf("\n");
	}
	
	return pass_correct_or_not;
}

void Admin_Mode(long admin_id)
{
	int order;
	long Entered_ID;

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
		Add_student_record(&head_student);
		break;
		
		case 2:
		printf("***********************************************************\n");
		printf("|                  Remove Student Record                  |\n");
		printf("***********************************************************\n");
		printf("\n");
		printf("Enter ID: ");
		scanf("%ld",&Entered_ID);
<<<<<<< HEAD
		Remove_student_record(&head_student,Entered_ID);
=======
		Remove_student_record (&head_student,Entered_ID);
>>>>>>> 445d6a118226d28634788f41b0215c68e4c7718f
		break;
		
		case 3:
		printf("***********************************************************\n");
		printf("|                  View Student Record                    |\n");
		printf("***********************************************************\n");
		printf("\n");
		printf("Enter ID: ");
		scanf("%ld",&Entered_ID);
		View_student_record(head_student,Entered_ID);
		break;
		
		case 4:
		printf("***********************************************************\n");
		printf("|                  View All Records                       |\n");
		printf("***********************************************************\n");
		printf("\n");
		View_all_records(head_student);
		break;
		
		case 5:
		printf("***********************************************************\n");
		printf("|                  Edit Admin Password                    |\n");
		printf("***********************************************************\n");
		printf("\n");
		Edit_Admin_Password(head_admin,admin_id);
		break;
		
		case 6:
		printf("***********************************************************\n");
		printf("|                  Edit Student Grade                     |\n");
		printf("***********************************************************\n");
		printf("\n");
		printf("Enter Student ID: ");
		scanf("%ld",&Entered_ID);
		Edit_student_grade(head_student,Entered_ID);
		break;
		
	}

}

void Student_Mode(long id)
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
		View_student_record(head_student,id);
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
		Edit_student_name(head_student,id);
		break;
		
	}
}
