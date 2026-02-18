#include <stdlib.h>
#include <stdio.h>

#include "sum.c"

// Для компеляции как ```  gcc -o some main.c sum.c query.c ``` закоментарить include и использовать говно снизу, ну и для всех файлов в том числе, но для нормальной работы использовать include и просто ``` gcc main.c -o main
/*
int Query(int L, int64_t S);
void Init(const int *arr, int n);
extern int64_t Sum(int l, int r);
extern int64_t SIZE;      // Объявляем как extern
extern int64_t *prefix;  // Объявляем как extern
*/

int Query(int L, int64_t S) {
    int R = SIZE;
    int64_t sum = Sum(L, SIZE); // а с херали вдруг функции теперь с большой буквы --> нарушение принятых правил наименования функций файлов и объектов
    while (sum > S) {
        if (L > R) {
            printf("FCK");
            exit(-1);
        }
        R -= 1;
        sum = Sum(L, R);
    }
    return R;
}
