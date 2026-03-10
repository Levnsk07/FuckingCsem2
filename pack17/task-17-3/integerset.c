
#include "integerset.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Специальный объект для пустого множества:
// указатель на него НЕ равен 0, но множество считается пустым.
static IntegerSet emptySet = { NULL, NULL, 0 };

// Вспомогательный компаратор для qsort
static int int_cmp(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

// Функция для создания нового узла
static IntegerSet* createNode(int value) {
    IntegerSet* newNode = (IntegerSet*)malloc(sizeof(IntegerSet));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Рекурсивная функция для добавления значения в дерево
static IntegerSet* insert(IntegerSet* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    // Если значение уже существует, дерево не меняем
    return root;
}

// Функция для создания множества из массива
IntegerSet* CreateSet(int* arr, int count) {
    // Пустое множество — вернуть не-NULL указатель
    if (count == 0) {
        return &emptySet;
    }

    // Проверка на дубликаты через сортировку копии массива (O(n log n), быстрее O(n^2))
    int *copy = (int *)malloc((size_t)count * sizeof(int));
    if (copy == NULL) {
        return 0;
    }
    memcpy(copy, arr, (size_t)count * sizeof(int));
    qsort(copy, (size_t)count, sizeof(int), int_cmp);
    for (int i = 1; i < count; ++i) {
        if (copy[i] == copy[i - 1]) {
            free(copy);
            return 0;
        }
    }
    free(copy);

    IntegerSet* root = NULL;
    for (int i = 0; i < count; ++i) {
        root = insert(root, arr[i]);
        if (root == NULL) {
            // Ошибка выделения памяти — считаем, что создать множество не удалось
            return 0;
        }
    }
    return root;
}

int IsInSet(IntegerSet* root, int value) {
    if (root == NULL || root == &emptySet) {
        return 0;
    }
    if (value == root->value) {
        return 1;
    }
    if (value < root->value) {
        return IsInSet(root->left, value);
    } else {
        return IsInSet(root->right, value);
    }
}