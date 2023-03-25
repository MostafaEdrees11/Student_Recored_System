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

#endif