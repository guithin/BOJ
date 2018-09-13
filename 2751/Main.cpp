#pragma warning(disable: 4996)
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

static int compare(const int *a, const int *b) {
	return (*a) - (*b);
}
static void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int* arr, int size, int element) {
	arr[++size] = element;
	for (int idx = size; idx > 1; idx >>= 1) {
		if (compare(&arr[idx], &arr[idx / 2]) < 0)
			swap(&arr[idx], &arr[idx / 2]);
		else break;
	}
}

void pop(int* arr, int size) {
	arr[1] = arr[size--];
	int child;
	for (int parent = 1; parent * 2 <= size; parent = child) {
		int left_child = parent * 2;
		int right_child = parent * 2 + 1;
		if (right_child > size || compare(&arr[left_child], &arr[right_child]) < 0) {
			child = left_child;
		}
		else
			child = right_child;
		if (compare(&arr[child], &arr[parent]) < 0)
			swap(&arr[child], &arr[parent]);
		else
			break;
	}
}

void heap_sort(int* arr, int size) {
	int root = 0;
	int* heap_arr = (int*)malloc(sizeof(int)*(size + 1));
	for (int i = 0; i < size; i++) {
		push(heap_arr, i, arr[i]);
	}
	for (int i = 0; i < size; i++) {
		arr[i] = heap_arr[1];
		pop(heap_arr, size - i);
	}
	free(heap_arr);
}

int main() {
	int n;
	int temp[1000010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", temp + i);
	}
	heap_sort(temp, n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", temp[i]);
	}
	return 0;
}