#include <stdio.h>
#include "tool.h"
#include "stAlg.h"

void exchangeSort(int* arr, int n) {
	int i, j;
	int temp;
	for (i = 0;i < n;i++) {
		for (j = i + 1;j < n;j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void mergeSort(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(start, mid, end, arr);
	}
}

void merge(int start, int mid, int end, int* arr) {
	int* result;
	int i = start;
	int j = mid + 1;
	int k = 0;
	int q;

	result = array(end - start + 1);

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			result[k] = arr[i];
			k++;
			i++;
		}
		else {
			result[k] = arr[j];
			k++;
			j++;
		}
	}

	// 남은 요소 추가 
	while (i <= mid) {
		result[k] = arr[i];
		k++;
		i++;
	}

	while (j <= end) {
		result[k] = arr[j];
		k++;
		j++;
	}

	for (i = start; i <= end; i++) {
		q = i - start;
		arr[i] = result[q];
	}

	freeArray(result);
}

void quickSort(int* arr, int l, int r) {
	if (l < r) {
		int j = partition(arr, l, r);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

int partition(int* arr, int l, int h){
	int pivot = arr[h];
	int i = l - 1;

	for (int j = l; j <= h - 1;j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void heapSort(int* arr, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		heap(n, i, arr);
	}
	for (int i = n - 1; i >= 0;i--) {
		swap(&arr[0], &arr[i]);
		heap(i, 0, arr); 
	}
}

void heap(int n, int i, int* arr) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (left<n && arr[left] >arr[largest]) {
		largest = left;
	}
	if (right<n && arr[right]>arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heap(n, largest, arr);
	}
}

void radixSort(int* arr, int n) {
	int temp[10000];
	int max = 0;
	int digit = 1;

	for (int i = 0;i < n;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	while (max / digit > 0) {
		int bucket[10] = { 0 }; // 0 ~ 9
		for (int i = 0; i < n;i++) {
			bucket[(arr[i] / digit) % 10]++;
		}
		for (int i = 1; i < 10;i++) {
			bucket[i] += bucket[i - 1];
		}

		for (int i = n - 1;i >= 0;i--) {
			temp[--bucket[arr[i] / digit % 10]] = arr[i];
		}

		for (int i = 0; i < n;i++) {
			arr[i] = temp[i];
		}
		digit *= 10;
	}
}
