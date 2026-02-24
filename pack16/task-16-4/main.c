#include <stdio.h>

// #include "factorize.c"

typedef struct Factors {
    int k;
    int primes[32];
    int powers[32];
} Factors;

// extern Factors factorize(int n);
extern void Factorize(int X, Factors *res);

int main() {

    freopen("input.txt", "r", stdin);

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int X;
        scanf("%d", &X);
        Factors res;
        Factorize(X, &res);
        printf("%d = ", X);
        if (res.k == 0) {
            printf("1\n");
            continue;
        }
        for (int j = 0; j < res.k; j++) {
            if (j > 0) printf(" * ");
            printf("%d^%d", res.primes[j], res.powers[j]);
        }
        printf("\n");
    }
    return 0;
}
