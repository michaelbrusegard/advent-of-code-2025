#include "../util.h" // Include your util header
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_lines;
    char **lines = read_lines_from_file("input.txt", &num_lines);
    if (lines == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    printf("Read %d lines:\n", num_lines);
    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %s\n", i + 1, lines[i]);
    }

    // Free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
