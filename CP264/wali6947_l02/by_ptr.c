/**
 * -------------------------------------
 * @file  by_ptr.c
 * Lab 2 Pointer Functions Source Code File
 * -------------------------------------
 * @author Ahmad Wali, 169036947, wali6947@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "by_ptr.h"

void fill_values_by_ptr(int *values, int size) {
    //pointer to values + i,
    for(int i = 0; i < size; i++) {
        *(values + i) = i + 1;
    }
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {
    for(int i = 0; i < size; i++){
            *(squares + i) = *(values + i) * *(values + i);
    }
}

void print_by_ptr(int *values, long int *squares, int size) {
    printf("%-5s  %-10s\n", "Value", "Square"); //the - tells it spaces and the number 5/10 how much, s is to allocate
        //it to a string passed into it, and d for integers.
    printf("-----  ----------\n");    for(int i = 0; i < size; i ++){
        printf("%-5d %-10d", *(values + i), *(squares + i));
    }
}