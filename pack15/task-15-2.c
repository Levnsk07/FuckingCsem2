#include <stdio.h>
int N = 0;

void printMat(double mat[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%0.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}


void forvord_move(double mat[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double f = mat[j][i] / mat[i][i];
            for (int k = i; k <= N; k++) {
                mat[j][k] = mat[j][k] - mat[i][k] * f;
            }
        }
    }

    double x[N];
    for (int i = N - 1; i >= 0; i--) {
        x[i] = mat[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    for (int i = 0; i < N; i++) {
        printf("%.10f\n",x[i]);
    }

}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    double mat[N][N + 1];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    forvord_move(mat);

    return 0;
}
