#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    char line[n];

    short mat[n][n];

    for (int i = 0; i < n; i++) {
        scanf("%s", line);
        for (int j = 0; j < n; j++) {
            if (line[j] == '1') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) mat[i][j] = 1;
            printf("%i", mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}
