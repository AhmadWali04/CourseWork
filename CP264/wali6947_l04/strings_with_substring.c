/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
 // Traverses every string in strings and prints the strings that contain substr. Case must match.
void strings_with_substring(strings_array *data, char *substr) {
    for (size_t y = 0; y < data->lines; ++y) {
        if (strstr(data->strings[y], substr) != NULL) {
            printf("%s\n", data->strings[y]);
        }
    }
}
