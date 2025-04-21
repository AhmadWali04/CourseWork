/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_three_integers(void) {
    int num1, num2, num3;
	int total = 0;
	while (1) {
        printf("Enter three comma-separated integers: ");
        if (scanf("%d,%d,%d", &num1, &num2, &num3) == 3) {
            total = num1 + num2 + num3;
            return total; 
        }//if
		else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n') {
                // Empty loop body
            }//while 2
            printf("The integers were not properly entered.\n");
        }//else
    }//while  
}//function

