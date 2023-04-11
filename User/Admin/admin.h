#ifndef ADMIN_H
#define ADMIN_H

#include "..\Student\student.h"

//refrential struct for admin

typedef struct admin
{
    char *m_adminName, *m_adminPassword;
    long m_adminID;
    struct admin* link;
}s_admin;


/*
---------------------------------------------------
			functions prototypes
---------------------------------------------------
*/
void View_all_records(s_student *head_student);
void Remove_student_record (s_student **head_student,long ID);
void Edit_student_grade(s_student *head_student,long ID);
void Add_student_record(s_student** head, char* name, char* gender, char* password, int grade, int age, long id);
void Edit_Admin_Password(s_admin* head, long id);
#endif