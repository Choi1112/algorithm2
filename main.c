#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "tool.h"
#include "stAlg.h"

void main() {
	int menu, n;
	int* arr;
	char* alg[5] = { "Exchange sort", "Merge sort", "Quick sort", "Heap sort", "Radix sort" }; // 정렬 알고리즘 메뉴 리스트 생성
	clock_t start = 0, end = 0; // 수행 시간 할당받을 변수

	while (1) {
		printf("Sorting algoritm menu\n");
		printf("1.Exchange sort\n2.Merge sort\n3.Quick sort\n4.Heap sort\n5.Radix sor\n6.Exit\n\n");
		printf("Selected sorting algoritm menu number : ");	// 정렬 알고리즘 선택
		scanf("%d", &menu);
		if (menu == 6) {	// EXIT 메뉴 선택시 Program End
			printf("Program End\n");
			break;
		}
		printf("Size of data(100/500/1000/5000/10000) : ");	// 데이터 크기 입력
		scanf("%d", &n);

		printf("\n%s", alg[menu-1]);
		printf("Result\n");

		for (int i = 0;i < 5;i++) {
			arr = array(n); // 1차원 배열의 동적할당
			randValue(arr, n); // 배열에 random 입력 데이터값 할당

			//printf("Original Array\n");
			//printArray(arr, n);
			printf("\n");

			if (menu == 1) {	// 교환 정렬 수행
				start = checkTime();
				exchangeSort(arr, n);
				//printArray(arr, n);
				end = checkTime();
			}
			else if (menu == 2) {	// 합병 정렬 수행
				start = checkTime();
				mergeSort(arr, 0, n - 1);
				//printArray(arr, n);
				end = checkTime();
			}
			else if (menu == 3) {	// 퀵 정렬 수행
				start = checkTime();
				quickSort(arr, 0, n - 1);
				//printArray(arr, n);
				end = checkTime();
			}
			else if (menu == 4) {	// 힙 정렬 수행
				start = checkTime();
				heapSort(arr, n);
				//printArray(arr, n);
				end = checkTime();
			}
			else if (menu == 5) {	// 기수 정렬 수행
				start = checkTime();
				radixSort(arr, n);
				//printArray(arr, n);
				end = checkTime();
			}
			else {	// 메뉴를 잘못입력한 경우(예외 처리)
				printf("It doesn't support the sorting algorithm selected by user\n");
			}

			printf("%d. execution time : %.3f", i+1, (float)(end - start) / CLOCKS_PER_SEC);	// 알고리즘 수행시간 출력
			freeArray(arr);	// 동적 할당 받은 배열 반환
		}
		printf("\n----------------------------------------------------------------------\n");
	}
}
