#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int* array(int n) {
    int* arr;
    arr = (int*)malloc(sizeof(int) * n);
    return arr;
}

void freeArray(int* arr) {
    free(arr);
}

void randValue(int* arr, int n) {
    int i;
    srand((unsigned)time(NULL));
    for (i = 0;i < n;i++) {
        arr[i] = rand() % 10000;
    }
}

void printArray(int* arr, int n) {
    int i;
    if (n <= 20) {
        for (i = 0;i < n;i++) {
            printf("%-5d  ", arr[i]);
        }
    }
    else {
        printf("Skip the test result. This is because the size of data is large.\n");
    }
}

clock_t checkTime() {
    clock_t time = clock();
    return time;
}
