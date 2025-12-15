#ifndef UTIL_H
#define UTIL_H

#define MAX_GRID_SIZE 1024

#include <stdbool.h>

char **read_lines_from_file(const char *filename, int *num_lines);
char **read_comma_separated_strings_from_file(const char *filename,
                                              int *num_strings);
bool is_in_array(int arr[], int size, int target);
long long digits_to_number(int arr[], int size);
bool read_grid_from_file(const char *filename,
                         char grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int *rows,
                         int *cols);

#endif
