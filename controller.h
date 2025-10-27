/*****************************************
* FileName: controller.h
* Descripton: defines functions in controller.c
* Author: Aiden Soroko
* Date: 10/7/2025
*****************************************/
#ifndef vector_h
#define vector_h

typedef struct
{
    char name[15];
    float i;
    float j;
    float k;
} vector;

#endif

vector create(char* name, float vali, float valj, float valk);
void output(vector vect);
