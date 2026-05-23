#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    int alpha[26] = {0};
    char c;

    while (fgetc(fp) != EOF) {
        c = fgetc(fp);
        if (c >= 'a' && c <= 'z') {
            alpha[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, alpha[i]);
    }

    fclose(fp);
}
