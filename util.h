#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

char **read_lines_from_file(const char *filename, int *num_lines);
char **read_comma_separated_strings_from_file(const char *filename,
                                              int *num_strings);
bool is_in_array(int arr[], int size, int target);
long long digits_to_number(int arr[], int size);

#endif
