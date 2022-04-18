#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tool.h"

// 두 변수에 들어 있는 값 서로 맞바꾸는 연산
void swap(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// 데이터 크기만큼의 1차원 배열 동적 할당
int* array(int n) {
    int* arr;
    arr = (int*)malloc(sizeof(int) * n);
    return arr;
}

// 동적 메모리 반환
void freeArray(int* arr) {
    free(arr);
}

// 배열에 0 ~ 9999 사이 랜덤값을 배열에 할당
void randValue(int* arr, int n) {
    int i;
    srand((unsigned)time(NULL));
    for (i = 0;i < n;i++) {
        arr[i] = rand() % 10000;
    }
}

// 배열을 출력하는 함수
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

// 프로세스, CPU 실행시간 측정 코드
clock_t checkTime() {
    clock_t time = clock();
    return time;
}
