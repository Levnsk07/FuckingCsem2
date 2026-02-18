#include <stdio.h>
#include <stdint.h>

#include "sum.c"
#include "query.c"

// extern void Init(const int *arr, int n);
// extern int64_t Sum(int l, int r);
// extern int Query(int l, int64_t sum);

int A[100005]; // Массив для хранения элементов

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Чтение массива A
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    // Инициализация префиксных сумм
    Init(A, N);

    // Обработка запросов
    for (int i = 0; i < M; ++i) {
        int L;
        int64_t S;
        scanf("%d %lld", &L, &S);
        int R = Query(L, S);
        printf("%d\n", R);
    }

    return 0;
}
