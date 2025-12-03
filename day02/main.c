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
        int part1 = atoi(strdup(token));
        token = strtok(NULL, "-");
        int part2 = atoi(strdup(token));
        for (int i = part1; i < part2; i++) {
            char *str;
            sprintf(str, "%d", i);
            int len = strlen(str);
            if (len % 2 == 0) {
                char *first = malloc(len / 2 + 1);
                char *second = malloc(len - len / 2 + 1);
                if (!first || !second) {
                    free(first);
                    free(second);
                    return 1;
                }
                memcpy(first, str, len / 2);
                first[len / 2] = '\0';
                memcpy(second, str + len / 2, len - len / 2);
                first[len - len / 2] = '\0';

                if (atoi(first) == atoi(second)) {
                    sum += i;
                }
                free(first);
                free(second);
            }
        }
    }
    printf("Part 1: %d\n", sum);

    return 0;
}
