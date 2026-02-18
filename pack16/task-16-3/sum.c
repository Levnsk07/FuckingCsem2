#include <stdint.h>

static int64_t prefix[100005]; // Глобальный массив для хранения префиксных сумм

// Подготовка массива префиксных сумм
void Init(const int *arr, int n) {
    prefix[0] = 0;

































































































    for (int i = 0; i < n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
}

// Вычисление суммы на отрезке [l, r)
int64_t Sum(int l, int r) {
    return prefix[r] - prefix[l];
}
