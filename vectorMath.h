/*****************************************
* FileName: vectorMath.h
* Descripton: Defines functions to be used
* in the vectorMath.c file
* Author: Aiden Soroko
* Date: 9/30/2025
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

vector add(char* name, vector a, vector b);
vector subtract(char* name, vector a, vector b);
void dot(vector a, vector b);
vector cross(char* name, vector a, vector b);
vector scalar(char* name, vector vect, float scale);
