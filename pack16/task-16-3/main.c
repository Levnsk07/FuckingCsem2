#include <stdio.h>
#include <stdint.h>

#include "query.c"


int main() {

    freopen("input.txt", "r", stdin);


    int N, M;
    scanf("%d %d", &N, &M);

    int A[N] = {};
    // Чтение массива A
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

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
