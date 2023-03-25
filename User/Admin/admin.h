#ifndef ADMIN_H
#define ADMIN_H

//refrential struct for admin

typedef struct admin
{
    char* m_adminName, m_adminPassword;
    long m_adminID;
    struct admin* link;
}s_admin;

#endif