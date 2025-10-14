/****************************************
* FileName: vectorMath.c
* Descripton: Will store, and preform various
* arithmetic operations on user inputted vectors
* Author: Aiden Soroko
* Date: 9/30/2025
*****************************************/

#include <stdio.h>
#include <string.h>
#include "vectorMath.h"
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

//adds ai + bi, aj + bj, ak + bk, and put it into c's i, j, k values
vector add(char* name, vector a, vector b)
{
    vector vect;
    strcpy(vect.name, name);
    vect.i = a.i + b.i;
    vect.j = a.j + b.j;
    vect.k = a.k + b.k;
    return vect;
}
//subtracts ai - bi, aj - bj, ak - bk, and put it into c's i, j, k values
vector subtract(char* name, vector a, vector b)
{
    vector vect;
    strcpy(vect.name, name);
    vect.i = a.i - b.i;
    vect.j = a.j - b.j;
    vect.k = a.k - b.k;
    return vect;
}
//returns the sum of ai * bi + aj * bj + ak * bk
void dot(vector vect, vector vect2)
{
    float temp = (vect.i*vect2.i)+(vect.j*vect2.j)+(vect.k*vect2.k);
    printf("%.2f\n",temp);
}
//does the cross product on vectors a and b and stores it into c
vector cross(char* name, vector a, vector b)
{
    vector vect;
    strcpy(vect.name, name);
    vect.i = (a.j*b.k) - (a.k*b.j);
    vect.j = (a.k*b.i) - (a.i*b.k);
    vect.k = (a.i*b.j) - (a.j*b.i);
    return vect;
}
//stores the value of i * scale, j * scale, k * scale into c's i, j, k values
vector scalar(char* name, vector vect, float scale)
{
    vector tempvect;
    strcpy(tempvect.name,name);
    tempvect.i = vect.i * scale;
    tempvect.j = vect.j * scale;
    tempvect.k = vect.k * scale;
    return tempvect;
}

