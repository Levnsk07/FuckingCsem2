#include <stdint.h>
#include "sum.c"

// Поиск самого длинного отрезка с началом в l и суммой не более sum
int Query(int l, int64_t sum) {
    int left = l;
    int right = sizeof(prefix) / sizeof(prefix[0]) - 1; // Максимально возможный правый край
    int result = l; // Изначально отрезок пустой

    // Бинарный поиск по правому краю
    while (left <= right) {
        int mid = (left + right) / 2;
        int64_t current_sum = Sum(l, mid);
        if (current_sum <= sum) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
