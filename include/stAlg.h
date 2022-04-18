#ifndef _STALG_

#define _STALG_

void exchangeSort(int* arr, int n);					// exchange sort 함수 
void mergeSort(int* arr, int start, int end);		// merge sort 함수 
void merge(int start, int mid, int end, int* arr);	// 합병 함수 
void quickSort(int* arr, int l, int r);				// quick sort 함수
int partition(int* arr, int l, int h);				// 분할 함수 
void heapSort(int* arr, int n);						// heap sort 함수
void heap(int n, int i, int* arr);					// MAX heap 
void radixSort(int* arr, int n);					// radix sort 함수

#endif
