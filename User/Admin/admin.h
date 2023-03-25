#ifndef ADMIN_H
#define ADMIN_H

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

#endif