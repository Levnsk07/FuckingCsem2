#ifndef INTEGERSET_H
#define INTEGERSET_H


// typedef struct IntegerSet IntegerSet;

typedef struct IntegerSet {
    struct IntegerSet* left;
    struct IntegerSet* right;
    int value;
}IntegerSet;


IntegerSet* CreateSet(int *arr, int count);

int IsInSet(IntegerSet *tree, int value);

#endif

