#include "../util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    chdir("day03");

    int num_lines;
    long long sum = 0;
    char **lines = read_lines_from_file("input.txt", &num_lines);

    if (lines == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    for (int i = 0; i < num_lines; i++) {
        int num1 = lines[i][0] - '0';
        int num1_index = 0;
        for (int j = 0; j < ((int)strlen(lines[i]) - 1); j++) {
            int current_num = lines[i][j] - '0';
            if (current_num > num1) {
                num1 = current_num;
                num1_index = j;
            }
        }
        int num2 = 0;
        for (int j = num1_index + 1; j < (int)strlen(lines[i]); j++) {
            int current_num = lines[i][j] - '0';
            if (current_num > num2) {
                num2 = current_num;
            }
        }
        int desired_num = (num1 * 10 + num2);
        sum += desired_num;
    }

    printf("Part 1: %lld\n", sum);

    sum = 0;

    for (int i = 0; i < num_lines; i++) {
        int indexes[12];
        memset(indexes, -1, sizeof(indexes));
        int numbers[12] = {0};
        for (int j = 0; j < 12; j++) {
            int start = (j == 0) ? 0 : indexes[j - 1] + 1;
            int end = strlen(lines[i]) - (12 - j);
            for (int k = start; k <= end; k++) {
                if (is_in_array(indexes, 12, k)) {
                    continue;
                }
                int current_num = lines[i][k] - '0';
                if (current_num > numbers[j]) {
                    numbers[j] = current_num;
                    indexes[j] = k;
                }
            }
        }
        sum += digits_to_number(numbers, 12);
    }
    printf("Part 2: %lld\n", sum);

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
