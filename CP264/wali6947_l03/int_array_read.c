/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
	for (int i = 0; i < size; ) {
        printf("Value for index %d: ", i);

        char input[50];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle error if fgets fails
            printf("Error reading input.\n");
            return;
        }

        // Attempt to convert the input to an integer
        int value;
        if (sscanf(input, "%d", &value) == 1) {
            *(array + i) = value;
            i++;
        } else {
            // If the conversion fails, print an error message
            printf("Not a valid integer\n");
        }
    }

	// your code here

}
