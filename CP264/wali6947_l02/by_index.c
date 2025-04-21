/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author Ahmad Wali, 169036947, wali6947@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {
    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}

void fill_squares_by_index(int values[], long int squares[], int size) {
    for(int i = 0; i<size;i++){
        squares[i] = values[i] * values[i];
    }
}

void print_by_index(int values[], long int squares[], int size) {
    printf("%-5s  %-10s\n", "Value", "Square"); // Header row
    printf("-----  ----------\n");
    for(int i = 0; i < size; i++){
        printf("%-5d %-10d\n",values[i],squares[i]);
    }
}
