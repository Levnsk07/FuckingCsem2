#include <stdint.h>
#include <stdlib.h>

static int64_t *prefix; // Глобальный массив для хранения префиксных сумм
static int64_t SIZE;
// Подготовка массива префиксных сумм
void Init(const int *arr, int n) {
    prefix = (int64_t *) malloc(sizeof(int64_t) * (n+1));
    SIZE = n;

    // prefix[0] = arr[0];
    // for (int i = 1; i < n; ++i) {
    //     prefix[i] = prefix[i - 1] + arr[i];
    // }

    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i-1];
    }
}

// Вычисление суммы на отрезке [l, r]
int64_t Sum(int l, int r) {
    return prefix[r] - prefix[l];
}
