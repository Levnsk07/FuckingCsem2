#include <stdio.h>

#include <stdio.h>
// int N = 0;
int sizeA = 0;
int sizeB = 0;


void printMat(double mat[sizeA][sizeB]) {
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            printf("%0.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}


void forvord_move(double mat[sizeA][sizeB]) {
    for (int i = 0; i < sizeA; i++) {
        for (int j = i + 1; j < sizeA; j++) {
            double f = mat[j][i] / mat[i][i];
            for (int k = i; k <= sizeA; k++) {
                mat[j][k] = mat[j][k] - mat[i][k] * f;
            }
        }
    }

    int x[sizeA];
    for (int i = sizeA - 1; i >= 0; i--) {
        x[i] = mat[i][sizeA];
        for (int j = i + 1; j < sizeA; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    for (int i = 0; i < sizeA; i++) {
        printf("%d\n", x[i]);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    sizeA = 4;
    sizeB = 4;
    // scanf("%d", &N);
    double mat[sizeA][sizeB + 1 ];
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB + 1; j++) {
            scanf("%lf", &mat[i][j]);
        }
        mat[i][sizeB] = 0;
    }

    forvord_move(mat);

    return 0;
}
