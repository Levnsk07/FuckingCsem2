#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b, long long *x, long long *y) { // Расшширенный алгоритм Евклида (НОД) для вычеслений коофицентов (xa + yb = gcd(a,b))
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

long long crt(long long a1, long long m1, long long a2, long long m2) {
    long long p, q;
    long long g = gcd(m1, m2, &p, &q);

    printf("%lld %lld %lld\n", g, p,q);

    if ((a1 - a2) % g != 0) {
        return -1; // Нет решения
    }

    long long lcm = m1 / g * m2;
    printf("%lld %lld / %lld * %lld\n",lcm,m1,g,m2);
    long long x = (a1 + (a2 - a1) / g * p % (m2 / g) * m1) % lcm;
    printf("%lld\n",x);
    if (x < 0) {
        x += lcm;
    }
    return x;
}

int main() {
    freopen("input.txt", "r", stdin);

    int k;
    scanf("%d", &k);

    long long *M = (long long *)malloc(k * sizeof(long long));
    long long *A = (long long *)malloc(k * sizeof(long long));

    for (int i = 0; i < k; ++i) {
        scanf("%lld", &M[i]);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%lld", &A[i]);
    }

    long long current_A = A[0];
    long long current_M = M[0];

    for (int i = 1; i < k; ++i) {
        long long p, q;
        current_A = crt(current_A, current_M, A[i], M[i]);
        current_M = current_M / gcd(current_M, M[i], &p, &q) * M[i];
    }

    printf("%lld\n", current_A);

    free(M);
    free(A);
    return 0;
}
