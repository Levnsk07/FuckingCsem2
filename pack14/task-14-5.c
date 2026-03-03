#include <stdio.h>

#define MAX_N 100000

long long int pow_mod(long long int a, long long int b, long long int mod) {
    // Теорема Фермы
    long long int result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

void precompute_factorials(long long m, long long *fact, long long *inv_fact) {
    m = m;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % m;
    }

    inv_fact[0] = pow_mod(fact[0], m - 2, m);
    inv_fact[1] = pow_mod(fact[1], m - 2, m);
    for (int i = 2; i <= MAX_N; ++i) {
        inv_fact[i] = pow_mod((fact[i]), m - 2, m);
    }
}


int main() {

    long long fact[MAX_N + 1];
    long long inv_fact[MAX_N + 1];

    freopen("input.txt", "r", stdin);

    unsigned int m = 1000000007;

    long t;
    scanf("%ld", &t);
    precompute_factorials(m,fact,inv_fact);

    for (int i = 0; i < t; ++i) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (n < k || k < 0) {
            printf("0\n");
        } else {
            printf("%llu\n", ((unsigned long long int) fact[n] % m * inv_fact[k] % m * inv_fact[n - k] % m) % m);
        }
    }

    fclose(stdin);
    return 0;
}
