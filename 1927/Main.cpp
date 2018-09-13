#include<stdio.h>
#include<algorithm>
using namespace std;

struct pos {
	int heap[100010];
	int size = 0;
	void add(int x) {
		size++;
		heap[size] = x;
		for (int i = size; i > 1; i /= 2) {
			if (heap[i / 2] > heap[i]) {
				swap(heap[i / 2], heap[i]);
			}
			else break;
		}
	}
	bool zero() {
		if (size == 0)return true;
		return false;
	}
	void nawa() {
		heap[1] = heap[size];
		size--;
		int child;
		for (int i = 1; i * 2 <= size; i = child) {
			if (size < i * 2 + 1)child = i * 2;
			else if (heap[i * 2] < heap[i * 2 + 1]) {
				child = i * 2;
			}
			else {
				child = i * 2 + 1;
			}
			if (heap[i] > heap[child]) {
				swap(heap[i], heap[child]);
			}
			else break;
		}
	}
	int atagkim() {
		return heap[1];
	}
	int kugi() {
		return size;
	}
};

pos hhhh;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			if (hhhh.zero()) {
				printf("0\n");
				continue;
			}
			printf("%d\n", hhhh.atagkim());
			hhhh.nawa();
			continue;
		}
		hhhh.add(n);
	}
	return 0;
}