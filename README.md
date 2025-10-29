## This program allows users to create upload and modify their own vectors using basic functions like add, subtract, cross and dot product.
## To build the program, either use the make file and make an executable, or run $ gcc -o vector main.c user.c vectorMath.c controller.c
## Commands to use
```
1. a = 1 1 1 - assigns a vector some inital values, can also override old values in vector\n"
all of the ones below can be used with or without the a = part
2. a = b + c - stores the value of b + c in a
3. a = b - c - stores the value of b - c in a
4. a = b * c - stores the value of b dot c in a
5. a = b x c - stores the value of b cross c in a
6. b * 2 - outputs the value of b * 2
7. quit - leaves the program
8. list - lists all of the sotred vectors
9. clear - clears the stored vectors
10. -h - brings up the help menu
```
## Program initally allocates enough memory for one vector to be stored, then each time the user creates the maximum number of vectors, the program will reallocate twice as much memory the next time