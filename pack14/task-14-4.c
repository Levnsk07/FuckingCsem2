#include <stdio.h>

long long int gcd(int a, int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    // freopen("input.txt", "r", stdin);
    int i;
    scanf("%lld", &i);
    while (i--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", gcd(a, b));
    }


    return 0;
}
