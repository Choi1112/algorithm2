#include <time.h>
#ifndef _TOOL_

#define _TOOL_

void swap(int* p, int* q);				// swap연산 수행
int* array(int n);						// 1차원 배열 동적할당
void freeArray(int* arr);				// 동적할당 메모리 반환
void randValue(int* arr, int n);		// 랜덤값 생성, 배열에 할당
void printArray(int* arr, int n);		// 배열 출력 함수
clock_t checkTime();					// 프로세서 및 cpu 시간 측정

#endif
