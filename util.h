#ifndef UTIL_H
#define UTIL_H

char **read_lines_from_file(const char *filename, int *num_lines);
char **read_comma_separated_strings_from_file(const char *filename, int *num_strings);

#endif