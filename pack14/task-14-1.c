#include <stdio.h>

long long int pow_mod(long long int a, long long int b, long long int mod) { // быстрое возведение в степень %= (a^b)%m
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

long long int find_inverse(long long int a, long long int m) {
    if (a == 0) {
        return -1;
    }
    return pow_mod(a, m - 2, m);    //  Малая теорема фермы -> a^(m-2) mod M = b(обратное)
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    long long int M;
    scanf("%d %lld", &T, &M);

    long long int a;
    for (int i = 0; i < T; i++) {
        scanf("%lld", &a);
        long long int inverse = find_inverse(a, M);
        printf("%lld\n", inverse);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}