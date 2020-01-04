//Libraries
#include <stdio.h>
#include <stdlib.h>
#include "assign2funcs.h"
#include <math.h>

int main (void){

//Constant Variables(MIN and MAXIMUM input values for vector length)
#define MIN 1
#define MAX 9

//Variables
int numval;     //NUMBER OF VECTOR VALUES
char ch;        //CHAR VARIABLE USED FOR CLEARING INPUT
int done = 0;   //VARIABLE TO KEEP TRACK WHEN USER ENTERS EOF
int validinput; //VARIABLE TO KEEP TRACK OF VALID INPUT INSIDE MAIN LOOP
int exitCode = 0; //EXIT CODE VARIABLE

/*
This loop keeps track of the main input of the user
it will iterate until the user enters EOF or 0.
*/
do{
        validinput = 0;
        //CHECKS FOR CORRECT INPUT
        if ((scanf("%d", &numval) != 1 || numval > MAX || numval < MIN )){
                validinput = 1;
                //IF INPUT IS 0 END the loop
                if (numval ==  0){
                        done = 1;
                }
                else{
                        exitCode = 1;
                        fprintf( stderr, "BAD INPUT\n");
                }
                //CLEARS INPUT WHEN USER ENTERS BAD INPUT
                while (validinput == 1){
                        scanf("%c",&ch);
                        if (ch == '\n'){
                                validinput = 0;
                        }
                }

        }
        else{
        double vector[numval];  //VECTOR ARRAY
        double nv[numval];      //NORMALIZED ARRAY
        double *normvector;     //POINTER FOR NORMALIZED ARRAY

        //INITIALIZES ARRAY IF INPUT IS VALID
        for (int i = 0; i < numval; i++){
                double temp;
                if (validinput ==0){
                if (scanf("%lf",&temp) == 1){
                        vector[i] = (double)temp;
                        nv[i] = (double)temp;
                }
                else{
                //CLEARS INPUT IF BAD INPUT
                        exitCode = 1;
                        fprintf( stderr, "BAD INPUT\n");
                        validinput = 1;
                        while (validinput == 1){
                                scanf("%c",&ch);
                                if (ch == '\n'){
                                        validinput = 0;
                                }
                        }
                        validinput = 1;
                        break;
                }
                }
        }
        //IF INPUT WAS VALID DISPLAY VECTOR AND NORMALIZED VECTOR
        if (validinput == 0){
        normvector = calcNorm(vector,numval);
        printf("[ VECTOR: ");
        for (int i = 0; i < numval; i++){
                if (i == numval - 1){
                        printf("%.3f", nv[i]);
                }
                else{
                        printf("%.3f, ", nv[i]);
                }
        }
        printf(" ]");

        printf("[ NORMALIZED: ");
        for (int i = 0; i < numval; i++){
                if (i == numval - 1){
                        printf("%.3f", normvector[i]);
                }
                else{
                        printf("%.3f, ", normvector[i]);
                }

        }
        printf(" ]\n");

        }
        }
}while(done == 0);

exit(exitCode);
}
