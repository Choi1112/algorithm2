#include <stdio.h>
#include <time.h>
#include "tool.h"
#include "stAlg.h"

void main() {
	int menu, n;
	int* arr;
	char *alg[5] = { "Exchange sort", "Merge sort", "Quick sort", "Heap sort", "Radix sort" };
	clock_t start = 0, end = 0;

	printf("Size of data(100/500/1000/5000/10000) : ");
	scanf("%d", &n);
	arr = array(n); // 1차원 배열의 동적할당
	randValue(arr, n); // 배열에 random 입력 데이터값 할당

	printf("Sorting algoritm menu\n\n");
	printf("1.Exchange sort\n2.Merge sort\n3.Quick sort\n4.Heap sort\n5.Radix sort\n\n");
	printf("Selected sorting algoritm menu number : ");
	scanf("%d", &menu);
	printf("\n\n");

	printf("Original Array\n");
	printArray(arr, n);
	printf("\n\n");

	printf("Result\n");
	if (menu == 1) {
		start = checkTime();
		exchangeSort(arr, n);
		printArray(arr, n);
		end = checkTime();
		printf("\n%s ", alg[0]);
	}
	else if (menu == 2) {
		start = checkTime();
		mergeSort(arr, n);
		printArray(arr, n);
		end = checkTime();
		printf("\n%s ", alg[1]);
	}
	else if (menu == 3) {
		start = checkTime();
		quickSort(arr, n);
		printArray(arr, n);
		end = checkTime();
		printf("\n%s ", alg[2]);
	}
  else if (menu == 4) {
		start = checkTime();
		heapSort(arr, n);
		printArray(arr, n);
		end = checkTime();
		printf("\n%s ", alg[3]);
	}
  else if (menu == 5) {
		start = checkTime();
		radixSort(arr, n);
		printArray(arr, n);
		end = checkTime();
		printf("\n%s ", alg[4]);
	}
	else {
		printf("It doesn't support the sorting algorithm selected by user\n");
	}

	printf("execution time : %.3f\n", (float)(end - start) / CLOCKS_PER_SEC);
	freeArray(arr);
}
