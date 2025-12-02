#include "../util.h"
#include <stdio.h>
#include <stdlib.h>

#define DIAL_SIZE 100
#define START_POSITION 50

int main() {
    int num_lines;
    int position = START_POSITION;
    int count = 0;
    char **lines = read_lines_from_file("input.txt", &num_lines);

    if (lines == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    for (int i = 0; i < num_lines; i++) {
        char direction = lines[i][0];
        int steps = atoi(lines[i] + 1);
        if (direction == 'L') {
            position = (position - steps) % DIAL_SIZE;
        } else if (direction == 'R') {
            position = (position + steps) % DIAL_SIZE;
        }
        if (position == 0) {
            count++;
        }
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    printf("%d\n", count);

    return 0;
}
