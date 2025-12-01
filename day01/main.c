#include "../util.h"

int main() {
    char* input = read_file("input.txt");
    if (input) {
        printf("%s\n", input);
        free(input);
    }
    return 0;
}