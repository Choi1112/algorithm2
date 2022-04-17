#ifndef _STALG_

#define _STALG_

void exchangeSort(int* arr, int n);
void mergeSort(int* arr, int start, int end);
void merge(int start, int mid, int end, int* arr);
void quickSort(int* arr, int l, int r);
int partition(int* arr, int l, int h);
void heapSort(int* arr, int n);
void heap(int n, int i, int* arr);
void radixSort(int* arr, int n);

#endif
