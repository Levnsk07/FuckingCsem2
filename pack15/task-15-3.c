#include <stdio.h>
#include <string.h>


int main() {
    FILE *inF = fopen("input.txt", "r");
    char line[101];
    fgets(line, sizeof(line), inF);
    fclose(inF);

    // flags
    int in_quotes = 0;

    int start = 0;
    int count = 0;

    char par[50][101];

    for (int i = 0; line[i+1] != '\n'; i++) {
//    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '"') { // change flag
            in_quotes = !in_quotes;
            memmove(&line[i], &line[i + 1], strlen(line) - i);
            i--;

        } else if (line[i] == ' ' && !in_quotes) {
            if (start < i) { // split
                strncpy(par[count], &line[start], i - start);
                par[count][i - start-1] = '\0';
                count++;
            }
            // add symb
            start = i + 1;
        }
    }

    if (start < strlen(line)) {
        strncpy(par[count], &line[start], strlen(line) - start);
        par[count][strlen(line) - start] = '\0';
        count++;
    }

    for (int i = 0; i < count; ++i) {
        printf("[%s]\n", par[i]);
    }


    return 0;
}
