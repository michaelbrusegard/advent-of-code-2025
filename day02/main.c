#include "../util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    chdir("day02");

    int sum = 0;
    int num_strings;
    char **strings =
        read_comma_separated_strings_from_file("input.txt", &num_strings);

    if (strings == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    for (int i = 0; i < num_strings; i++) {
        char *token = strtok(strings[i], "-");
        int part1 = atoi(token);
        token = strtok(NULL, "-");
        int part2 = atoi(token);
        for (int j = part1; j <= part2; j++) {
            char *str = malloc(20);
            sprintf(str, "%d", j);
            int len = strlen(str);
            if (len % 2 == 0) {
                char *first = malloc(len / 2 + 1);
                char *second = malloc(len - len / 2 + 1);
                if (!first || !second) {
                    free(first);
                    free(second);
                    free(str);
                    return 1;
                }
                memcpy(first, str, len / 2);
                first[len / 2] = '\0';
                memcpy(second, str + len / 2, len - len / 2);
                second[len - len / 2] = '\0';

                if (atoi(first) == atoi(second)) {
                    sum += j;
                }
                free(first);
                free(second);
                free(str);
            }
        }
    }
    printf("Part 1: %d\n", sum);

    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
