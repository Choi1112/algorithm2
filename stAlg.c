#include <stdio.h>
#include "tool.h"
#include "stAlg.h"

// 교환 정렬 함수 
void exchangeSort(int* arr, int n) {
	int i, j;
	int temp;
	for (i = 0;i < n;i++) {
		for (j = i + 1;j < n;j++) {
			if (arr[i] > arr[j]) {	// 데이터 비교, swap연산 수행 
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// 합병 정렬 : divide and conquer
void mergeSort(int* arr, int start, int end) {	// 배열의 시작 인덱스, 끝 인덱스 
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);		// 하위 목록으로 분할
		mergeSort(arr, mid + 1, end);
		merge(start, mid, end, arr);	// 병합
	}
}

// 병합 함수
void merge(int start, int mid, int end, int* arr) {
	int* result;
	int i = start;
	int j = mid + 1;
	int k = 0;
	int q;

	result = array(end - start + 1);	//추가적인 배열 공간 사용

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

	// 배열에 정렬된 값 할당
	for (i = start; i <= end; i++) {
		q = i - start;
		arr[i] = result[q];
	}

	freeArray(result);
}

// 퀵 정렬 구현 함수 
void quickSort(int* arr, int l, int r) {
	if (l < r) {
		int j = partition(arr, l, r); // pivot의 인덱스, 배열에 정렬된 pivot 위치   
		quickSort(arr, l, j - 1);	// pivot 인덱스 하위 목록
		quickSort(arr, j + 1, r);	// pivot 인덱스 상위 목록
	}
}

// pivot 설정, 배열에 pivot 요소를 올바른 위치로 옮김 
int partition(int* arr, int l, int h){
	int pivot = arr[h];	// arr 배열의 마지막 요소 pivot 설정
	int i = l - 1;

	for (int j = l; j <= h - 1;j++) {
		if (arr[j] <= pivot) {	// 배열의 arr[j] 값 pivot보다 작거나 같으면 arr[i], arr[j] 두 값 swap연산 
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[h]); // 마지막으로 올바른 위치에 pivot 오도록 swap
	return (i + 1);
}

// 힙 정렬 구현 함수
void heapSort(int* arr, int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		heap(n, i, arr);	// 초기의 최대 힙 생성 (최대 힙 - 상위 노드가 두 하위 노드보다 큰 이진트리)	
	}
	for (int i = n - 1; i >= 0;i--) {	// 가장 큰 요소(root) 바꾸고, heap() - 최대 힙 생성 함수 수행 
		swap(&arr[0], &arr[i]);
		heap(i, 0, arr); 
	}
}

// 최대 힙 생성 함수 
void heap(int n, int i, int* arr) {
	int left = 2 * i + 1;	// 왼쪽 child에 해당하는 배열 인덱스
	int right = 2 * i + 2;	// 오른쪽 child에 해당하는 배열 인덱스
	int largest = i;

	if (left<n && arr[left] >arr[largest]) {	// 왼쪽 child 존재여부 && root 보다 큰지 확인 
		largest = left;
	}
	if (right<n && arr[right]>arr[largest]) {	// 오른쪽 child 존재여부 && root 보다 큰지 확인
		largest = right;
	}
	if (largest != i) {	// root가 가장 크지 않는 경우
		swap(&arr[i], &arr[largest]);	// swap 연산 수행하여 루트를 가장 크게 만든다.
		heap(n, largest, arr);			// 최대 힙 구현까지 반복 수행
	}
}

// 기수 정렬 구현 함수 
void radixSort(int* arr, int n) {
	int temp[10000];
	int max = 0;
	int digit = 1;

	for (int i = 0;i < n;i++) {
		if (arr[i] > max) {
			max = arr[i];	// 최대 자릿수를 가진 배열의 최댓값 
		}
	}

	while (max / digit > 0) {	// max값이 자릿수보다 클 때 반복, 작으면 종료 
		int bucket[10] = { 0 }; // 0 ~ 9
		for (int i = 0; i < n;i++) {
			bucket[(arr[i] / digit) % 10]++;	// 자릿수 배열 bucket 처리 함수 (나머지 이용)
		}
		for (int i = 1; i < 10;i++) {
			bucket[i] += bucket[i - 1];			// 누적 자릿수 배열 처리
		}

		for (int i = n - 1;i >= 0;i--) {
			temp[--bucket[arr[i] / digit % 10]] = arr[i];	// temp 배열에 값들이 정렬되어 할당된다. 
		}

		for (int i = 0; i < n;i++) {
			arr[i] = temp[i];	// 정렬된 배열로 기존 배열 갱신 
		}
		digit *= 10;	// 자릿수 증가
	}
}
