#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_lines_from_file(const char *filename, int *num_lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *num_lines = 0;
        return NULL;
    }

    int capacity = 16;
    int count = 0;
    char **lines = malloc(capacity * sizeof(char *));
    if (lines == NULL) {
        fclose(file);
        *num_lines = 0;
        return NULL;
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        lines[count] = strdup(buffer);
        if (lines[count] == NULL) {
            goto cleanup;
        }
        count++;

        if (count >= capacity) {
            capacity *= 2;
            char **temp = realloc(lines, capacity * sizeof(char *));
            if (temp == NULL) {
                goto cleanup;
            }
            lines = temp;
        }
    }
    fclose(file);
    *num_lines = count;
    return lines;

cleanup:
    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }
    free(lines);
    fclose(file);
    *num_lines = 0;
    return NULL;
}

char **read_comma_separated_strings_from_file(const char *filename,
                                              int *num_strings) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *num_strings = 0;
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t result = getline(&line, &len, file);
    if (result > 0 && line[result - 1] == '\n') {
        line[result - 1] = '\0';
    }

    if (result == -1) {
        free(line);
        fclose(file);
        *num_strings = 0;
        return NULL;
    }

    int capacity = 16;
    int count = 0;
    char **strings = malloc(capacity * sizeof(char *));
    if (strings == NULL) {
        free(line);
        fclose(file);
        *num_strings = 0;
        return NULL;
    };

    char *token = strtok(line, ",");
    while (token) {
        strings[count] = strdup(token);
        count++;

        if (count >= capacity) {
            capacity *= 2;
            char **temp = realloc(strings, capacity * sizeof(char *));
            if (temp == NULL) {
                goto cleanup;
            }
            strings = temp;
        }
        token = strtok(NULL, ",");
    }

    free(line);
    fclose(file);
    *num_strings = count;
    return strings;

cleanup:
    for (int i = 0; i < count; i++) {
        free(strings[i]);
    }
    free(strings);
    free(line);
    fclose(file);
    *num_strings = 0;
    return NULL;
}

bool is_in_array(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

long long digits_to_number(int arr[], int size) {
    long long number = 0;
    for (int i = 0; i < size; i++) {
        number = number * 10 + arr[i];
    }
    return number;
}

bool read_grid_from_file(const char *filename,
                         char grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int *rows,
                         int *cols) {
    *rows = 0;
    *cols = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    char line[MAX_GRID_SIZE + 2];

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        size_t len = strlen(line);

        if (len == 0)
            continue;

        if (*rows >= MAX_GRID_SIZE) {
            fprintf(stderr, "Too many rows\n");
            return false;
        }

        if (*cols == 0) {
            *cols = len;
        } else if (len != *cols) {
            fprintf(stderr, "Inconsistent line length\n");
            return false;
        }

        if (*cols > MAX_GRID_SIZE) {
            fprintf(stderr, "Too many columns\n");
            return false;
        }

        for (int i = 0; i < *cols; i++) {
            grid[*rows][i] = line[i];
        }

        (*rows)++;
    }
    return true;
}
