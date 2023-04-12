#ifndef SYSTEM_H
#define SYSTEM_H

// Total_Length is a macro used to specifiy length of printing (variable + white spaces)
#define Total_Length 30

#include "..\User\Student\student.h"

/*
---------------------------------------------------
			functions prototypes
---------------------------------------------------
*/
void print_int(int num);
void print_string(char *string, int len);

void View_student_record(s_student *head,long ID);


#endif