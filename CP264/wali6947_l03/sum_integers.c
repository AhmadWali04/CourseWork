/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Ahmad, 169036947, wali6947@mylaurier.ca
 * @version 2025-01-06
 *
 * -------------------------------------
 */ 
#include "functions.h"

int sum_integers(void) {
    int total = 0;
    int num;

    while (1) {
        printf("Enter an integer (or a non-integer to stop): ");
        if (scanf("%d", &num) == 1) {
            total += num;
        }//if
		else {
            break;
        }//else
    }//whle
    return total;
}