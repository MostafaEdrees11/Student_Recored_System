#ifndef _Application_H_
#define _Application_H_


/*
---------------------------------------------------
			functions prototypes
---------------------------------------------------
*/
void Start_Program(void);
void Login(void);
int Check_Password(char *password);
void Admin_Mode(s_admin *ptr_admin,long admin_id);
void Student_Mode(s_student *ptr_student,long id);


#endif