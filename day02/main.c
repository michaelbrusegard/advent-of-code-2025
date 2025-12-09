#include "../util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    chdir("day02");

    long long sum = 0;
    int num_strings;
    char **strings =
        read_comma_separated_strings_from_file("input.txt", &num_strings);

    if (strings == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    for (int i = 0; i < num_strings; i++) {
        char *token = strtok(strings[i], "-");
        long long part1 = strtoll(token, NULL, 10);
        token = strtok(NULL, "-");
        long long part2 = strtoll(token, NULL, 10);
        for (long long j = part1; j <= part2; j++) {
            char *str = malloc(20);
            sprintf(str, "%lld", j);
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
            }
            free(str);
        }
    }
    printf("Part 1: %lld\n", sum);
    sum = 0;

    for (int i = 0; i < num_strings; i++) {
        char *token = strings[i];
        char *end;
        long long part1 = strtoll(token, &end, 10);
        token = end + 1;
        long long part2 = strtoll(token, NULL, 10);
        for (long long j = part1; j <= part2; j++) {
            char *str = malloc(20);
            sprintf(str, "%lld", j);
            int len = strlen(str);

            int is_invalid = 0;
            for (int k = 1; k <= len / 2; k++) {
                if (len % k != 0)
                    continue;
                char *test = malloc(20);
                for (int l = 0; l < len; l++) {
                    test[l] = str[l % k];
                }
                test[len] = '\0';
                if (strcmp(str, test) == 0) {
                    is_invalid = 1;
                }
                free(test);
                if (is_invalid)
                    break;
            }
            if (is_invalid) {
                sum += j;
            }
            free(str);
        }
    }
    printf("Part 2: %lld\n", sum);

    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
