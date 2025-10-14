/****************************************
* FileName: controller.c
* Descripton: Will keep the program 
* running, and store all necessary data
* Author: Aiden Soroko
* Date: 10/7/2025
*****************************************/

#include <stdio.h>
#include <string.h>
#include "vectorMath.h"
#include "controller.h"
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
//assigns a vector a name, and its i, j, k values
vector create(char* named, float vali, float valj, float valk){
    vector vect;
    strcpy(vect.name, named);
    vect.i = vali;
    vect.j = valj;
    vect.k = valk;
    return vect;
}
//outputs the vector name, and its i, j, k values
void output(vector vect){
    printf("%s  = %.2f  %.2f  %.2f\n",vect.name,vect.i,vect.j,vect.k);
}
