/*****************************************
* FileName: user.c
* Descripton: Will keep the program 
* running, and store all necessary data
* Author: Aiden Soroko
* Date: 10/7/2025
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
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

int run(){
    //define variables
    vector array[10];
    int count = 0;
    char *token;
    bool continues = true;
    char userinput[100];
    char* tokened[5];
    vector ans;
    ans.i = 0;
    ans.j = 0;
    ans.k = 0;

    strcpy(ans.name,"ans");

    while (continues){
        int whereLocated = 0;
        bool noDisplay = false;
        printf("command> ");
        //get user input
        fgets(userinput, 100, stdin);
        userinput[strcspn(userinput, "\n")] = '\0';
        int i = 0;
        token = strtok(userinput, " ");
        //break the input up into tokens
        while (token != NULL){
            tokened[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        //check if the user wants to quit or get help
        if (strcmp(tokened[0],"quit") == 0){
            continues = false;
        } else if(strcmp(tokened[0],"-h") == 0){
            printf("Commands to use\n"
                "a = 1 1 1 - assigns a vector some inital values, can also override old values in vector\n"
                "all of the ones below can be used with or without the a = part\n"
                "a = b + c - stores the value of b + c in a\n"
                "a = b - c - stores the value of b - c in a\n"
                "a = b * c - stores the value of b dot c in a\n"
                "a = b x c - stores the value of b cross c in a\n"
                "b * 2 - outputs the value of b * 2\n"
                "quit - leaves the program\n"
                "list - lists all of the sotred vectors\n"
                "clear - clears the stored vectors\n");
            
        } else if(strcmp(tokened[0],"clear") == 0){
            count = 0;
        } else if(strcmp(tokened[0],"list") == 0){
            for (int j = 0; j < count ; j++){
                printf("%s %.2f %.2f %.2f\n",array[j].name,array[j].i,array[j].j,array[j].k);
            }
        }else {
            if (isdigit(tokened[0][0]) == 0){
                //check for already made vectors of the inputted name
                bool dupe = false;
                for (int j = 0; j < count && !dupe; j++){
                    if (strcmp(array[j].name,tokened[0]) == 0){
                        dupe = true;
                    } else {
                        printf("%d",j);
                        whereLocated++;
                    }
                }
                bool val1dupe = true;
                bool val2dupe = true;
                //checking to see if the inputted vectors after the equals sign are defined
                if (i == 3){
                    if (count != 0){
                        val1dupe = false;
                        val2dupe = false;
                    }
                    for (int j = 0; j < count && !val1dupe; j++){
                        if (strcmp(array[j].name,tokened[0]) == 0 || isdigit(tokened[0][0]) != 0){
                            val1dupe = true;
                        } 
                    }
                    for (int j = 0; j < count && !val2dupe; j++){
                        if (strcmp(array[j].name,tokened[2]) == 0 || isdigit(tokened[2][0]) != 0){
                            val2dupe = true;
                        } 
                    }
                    //checking to see if the vectors are defined when no equals sign in present
                } else if (i == 5){
                    if (count != 0){
                        val1dupe = false;
                        val2dupe = false;
                    }
                    for (int j = 0; j < count && !val1dupe; j++){
                        if (strcmp(array[j].name,tokened[2]) == 0 || isdigit(tokened[2][0]) != 0){
                            val1dupe = true;
                        } 
                    }
                    for (int j = 0; j < count && !val2dupe; j++){
                        if (strcmp(array[j].name,tokened[4]) == 0 || isdigit(tokened[4][0]) != 0){
                            val2dupe = true;
                        } 
                    }
                }  
                //check if the list is full and can't accept new vectors
                if (count == 10 && !dupe){
                    printf("list is full, try clearing if you want more vectors\n");
                    //check to se if the vector wanting to be displayed is defined
                } else if(!dupe && i == 1){
                    printf("No vector to be displayed\n");
                    noDisplay = true;
                    //check if the vectors on the right hand side of the equals sign are defined
                } else if (!val2dupe || !val1dupe){
                    printf("One of the vectors doesn't exist\n");
                    noDisplay = true;
                    //if this isn't a duped vector, create a new one with i,j,k values of 0,0,0
                } else if(!dupe){
                    array[whereLocated] = create(tokened[0],0,0,0);
                    count++;
                } 
            }
            if (!noDisplay){
                //check if it is in the form a = 0 0 0 
                if(isdigit(tokened[2][0]) != 0 && isdigit(tokened[3][0]) != 0 && isdigit(tokened[4][0]) != 0){
                    array[whereLocated].i = atof(tokened[2]);
                    array[whereLocated].j = atof(tokened[3]);
                    array[whereLocated].k = atof(tokened[4]);
                    output(array[whereLocated]);
                    //check if it is in the a form to display
                }else if(strcmp(tokened[1],"\0") == 0){
                    output(array[whereLocated]);
                    //check if there is an equal sign
                } else if(strcmp(tokened[1],"=") == 0){
                    //find out which vectors are in the equation
                    vector val1;
                    vector val2;
                    bool valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[2]) == 0){
                            valfound = true;
                            val1 = array[j];
                        }
                    }
                    valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[4]) == 0){
                            valfound = true;
                            val2 = array[j];
                        }
                    }
                    //if addition, add the vectors and put them in the given vector
                    if(strcmp(tokened[3],"+") == 0){
                        array[whereLocated] = add(array[whereLocated].name,val1,val2);
                        output(array[whereLocated]);
                    //if subtraction, subtract the vectors and put them in the given vector
                    } else if(strcmp(tokened[3],"-") == 0){
                        array[whereLocated] = subtract(array[whereLocated].name,val1,val2);
                        output(array[whereLocated]);
                    //if scalar multiplication, multiply the vectors and put them in the given vector
                    } else if(strcmp(tokened[3],"*") == 0){
                        vector newval1;
                        int scalarval1 = 0;
                        vector newval2;
                        int scalerval2 = 0;
                        if (isdigit(tokened[2][0]) != 0){
                            scalarval1 = atoi(tokened[2]);
                        } else {
                            bool valfound = false;
                            for (int j = 0; j < count && !valfound; j++){
                                if (strcmp(array[j].name,tokened[2]) == 0){
                                    valfound = true;
                                    newval1 = array[j];
                                }
                            }
                        }
                        if (isdigit(tokened[4][0]) != 0){
                            scalerval2 = atoi(tokened[4]);
                        } else {
                            bool valfound = false;
                            for (int j = 0; j < count && !valfound; j++){
                                if (strcmp(array[j].name,tokened[4]) == 0){
                                    valfound = true;
                                    newval2 = array[j];
                                }
                            }
                        }
                        if (scalarval1 != 0){
                            array[whereLocated] = scalar(array[whereLocated].name,newval2,scalarval1);
                            output(array[whereLocated]);
                        } else if (scalerval2 != 0){
                            array[whereLocated] = scalar(array[whereLocated].name,newval1,scalerval2);
                            output(array[whereLocated]);
                        }
                    //if cross product, cross the vectors and put them in the given vector
                    } else if(strcmp(tokened[3],"x") == 0){
                        array[whereLocated] = cross(array[whereLocated].name,val1,val2);
                        output(array[whereLocated]);
                    }
                    //same as the ones above, just without the = given
                } else if(strcmp(tokened[1],"+") == 0){
                    vector val1;
                    vector val2;
                    bool valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[0]) == 0){
                            valfound = true;
                            val1 = array[j];
                        }
                    }
                    valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[2]) == 0){
                            valfound = true;
                            val2 = array[j];
                        }
                    }
                    ans = add(ans.name,val1,val2);
                    output(ans);
                    
                } else if(strcmp(tokened[1],"-") == 0){
                    vector val1;
                    vector val2;
                    bool valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[0]) == 0){
                            valfound = true;
                            val1 = array[j];
                        }
                    }
                    valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[2]) == 0){
                            valfound = true;
                            val2 = array[j];
                        }
                    }
                    ans = subtract(ans.name,val1,val2);
                    output(ans);
                    
                } else if(strcmp(tokened[1],"*") == 0){
                    //check to see if the given values are vectors or numbers
                    vector val1;
                    int scalarval1 = 0;
                    vector val2;
                    int scalerval2 = 0;
                    if (isdigit(tokened[0][0]) != 0){
                        scalarval1 = atoi(tokened[0]);
                    } else {
                        bool valfound = false;
                        for (int j = 0; j < count && !valfound; j++){
                            if (strcmp(array[j].name,tokened[0]) == 0){
                                valfound = true;
                                val1 = array[j];
                            }
                        }
                    }
                    if (isdigit(tokened[2][0]) != 0){
                        scalerval2 = atoi(tokened[2]);
                    } else {
                        bool valfound = false;
                        for (int j = 0; j < count && !valfound; j++){
                            if (strcmp(array[j].name,tokened[2]) == 0){
                                valfound = true;
                                val2 = array[j];
                            }
                        }
                    }
                    //if either value given is a number, do scalar, if not do dot product
                    if (scalarval1 != 0){
                        ans = scalar("ans",val2,scalarval1);
                        output(ans);
                    } else if (scalerval2 != 0){
                        ans = scalar("ans",val1,scalerval2);
                        output(ans);
                    } else{
                        dot(val1,val2);
                    }   
                } else if(strcmp(tokened[1],"x") == 0){
                    vector val1;
                    vector val2;
                    bool valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[0]) == 0){
                            valfound = true;
                            val1 = array[j];
                        }
                    }
                    valfound = false;
                    for (int j = 0; j < count && !valfound; j++){
                        if (strcmp(array[j].name,tokened[2]) == 0){
                            valfound = true;
                            val2 = array[j];
                        }
                    }
                    ans = cross(ans.name,val1,val2);
                    output(ans);
                } else {
                    printf("invalid input\n");
                }
            }
        }
    }

    return 0;
}