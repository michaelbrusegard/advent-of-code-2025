#include "../util.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    chdir("day04");

    int num_lines;
    int count = 0;
    char **lines = read_lines_from_file("input.txt", &num_lines);

    if (lines == NULL) {
        printf("Error reading file\n");
        return 1;
    }
    printf("Part 1: %d\n", count);

    printf("Part 2: %d\n", count);

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
