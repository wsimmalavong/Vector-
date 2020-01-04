/*
Author: William Simmalavong
Purpose: Functions of calculating length and functions of calculating norm
*/


#include <math.h> // UTILIZATION OF MATH FOR SQRT AND POW FUNCTIONS
#include <stdio.h>
#include <stdlib.h>
#include "assign2funcs.h"

/*
NAME: CALCLENGTH
PURPOSE: CALCUALTE THE LENGTH OF THE ARRAY GIVEN THE DEFINTION
INPUT: VECTOR ARRAY AND NUMBER OF VALUES
REUTRN: RETURNS A DOUBLE VALUE OF THE LENGTH OF THE ARRAY
*/
double calcLength(double vector[],int numval){
        int sum = 0;
        for (int i = 0; i < numval; i++){
                sum = sum + pow(vector[i], 2);
        }
        sum = sqrt(sum);
        return sum;
}
/*
NAME: CALCNORM
PURPOSE: NORMALIZE GIVEN ARRAY
INPUT: VECOTR ARRAY AND NUMBER OF VALUES IN ARRAY
RETURN: A POINTER VALUE TO THE NORMALIZED ARRAY
*/
double * calcNorm(double vector[],int numval){
        double length = calcLength(vector,numval);
        for (int i = 0; i < numval; i++){
                vector[i] = vector[i]/length;
        }
        return vector;
}

