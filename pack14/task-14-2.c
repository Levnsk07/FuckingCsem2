#include <stdio.h>
#define MAX_N 2000

long long fact[MAX_N + 1];
long long inv_fact[MAX_N + 1];
long long M;

long long int pow_mod(long long int a, long long int b, long long int mod) {    // см task-14-1
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
void precompute_factorials(long long m) {   //  создание двух массивов факториалов (обычного и обратного)
    M = m;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % M;
    }

    inv_fact[0] =pow_mod(fact[0], M - 2, M);
    inv_fact[1] =pow_mod(fact[1], M - 2, M);

    for (int i = 2; i <= MAX_N; ++i) {
        inv_fact[i] = pow_mod((fact[i]) ,m-2, M);
    }

}


int main() {
    freopen("input.txt", "r", stdin);

    long m, t;
    scanf("%ld %ld", &m, &t);
    precompute_factorials(m);

    for (int i = 0; i < t; ++i) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (n < k || k < 0) {
            printf("0\n");
        } else {
            printf("%lld\n", (fact[n]*  inv_fact[k] * inv_fact[n - k]) % M);    //  в свойствах модулей нет деления, но есть умножение, поэтому вместу деление обратное
        }
    }

    fclose(stdin);


    return 0;
}
