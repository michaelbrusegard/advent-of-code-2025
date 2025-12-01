#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_lines_from_file(const char *filename, int *num_lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *num_lines = 0;
        return NULL
    }

    int capacity = 16;
    int count = 0;
    char **lines = malloc(capacity * sizeof(char *));
    if (lines == NULL) {
        fclose(file);
        *num_lines = 0;
        return NULL
    }

    char buffer[1024]

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
