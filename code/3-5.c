#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char buffer[256];
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        char* end;
        long val = strtol(buffer, &end, 10);

        if (end == buffer || (*end != '\n' && *end != '\0')) {
            fprintf(stderr, "invalid input %s", buffer);
        } else {
            sum += val;
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
