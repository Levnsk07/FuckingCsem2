#include <stdio.h>
#include <stdint.h>

#include "query.c"


// Для компеляции как ```gcc -o some main.c sum.c query.c``` закоментарить include и использовать говно снизу, ну и для всех файлов в том числе, но для нормальной работы использовать include и просто ``` gcc main.c -o main
// void Init(const int *arr, int n);
// int64_t Sum(int l, int r);
// int Query(int L, int64_t S);


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
