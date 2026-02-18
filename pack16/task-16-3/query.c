#include "sum.c"
#include <stdlib.h>
#include <stdio.h>

int Query(int L, int64_t S) {
    int R = SIZE;
    int64_t sum = Sum(L, SIZE);
    // а с херали вдруг функции теперь с большой буквы --> нарушение принятых правил наименования функций файлов и объектов
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
