#ifndef _Application_H_
#define _Application_H_

void Start_Program(void);
void Login(s_admin *head_admin, s_student *head_student);
int Check_Password(char *password);
void Admin_Mode(void);
void Student_Mode(void);


#endif