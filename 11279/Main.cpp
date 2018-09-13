#include<stdio.h>
#include<algorithm>
using namespace std;

struct Heap {
	int arr[100010];
	int size;

	int top() {
		return arr[1];
	}

	void push(int x) {
		arr[++size] = x;
		for (int cur = size; cur > 1; cur /= 2) {
			if (arr[cur] > arr[cur / 2]) {
				swap(arr[cur], arr[cur / 2]);
			}
			else
				break;
		}
	}

	void pop() {
		arr[1] = arr[size--];
		int child;
		for (int cur = 1; cur * 2 <= size; cur = child) {
			if (cur * 2 + 1 <= size && arr[cur * 2 + 1] > arr[cur * 2]) {
				child = cur * 2 + 1;
			}
			else
				child = cur * 2;
			if (arr[cur] < arr[child])
				swap(arr[cur], arr[child]);
			else
				break;
		}
	}

	int _size() {
		return size;
	}

	Heap() {
		size = 0;
	}
};

Heap heap;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 0) {
			if (heap._size() == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", heap.top());
				heap.pop();
			}
		}
		else {
			heap.push(temp);
		}
	}
	return 0;
}