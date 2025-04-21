/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"
#include "string.h"


void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {
    for (int y = 0; y < data->lines; ++y) {
        int num = strlen(data->strings[y]);
        if (num < length) {
            fprintf(fp_short, "%s\n", data->strings[y]);
        } else {
            fprintf(fp_long, "%s\n", data->strings[y]);
        }
    }

}
