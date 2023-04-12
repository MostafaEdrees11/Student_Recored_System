#ifndef STUDENT_H
#define STUDENT_H

//refrential struct for student

typedef struct student
{
    char *m_name, *m_gender, *m_password;
    int m_grade, m_age;
    long m_id;
    struct student* link;
}s_student;

/*
---------------------------------------------------
            functions prototypes
---------------------------------------------------
*/

void Edit_student_name(s_student *head_student,long ID);
void Edit_Student_Password(s_student* head, long id);
void add_student_at_start(void);

#endif