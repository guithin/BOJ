#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int stack[10005];
int size = 0;
		char com[10] = {};

void push(int a) {
	stack[size] = a;
	size++;
}

int pop() {
	if (size == 0) return -1;
	else {
		size--;
		return stack[size];
	}
}

int siz() {
	return size;
}

int top() {
	if (size == 0) return -1;
	return stack[size - 1];
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", com);
		if (strcmp(com, "push") == 0) {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(com, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(com, "size") == 0) {
			printf("%d\n", siz());
		}
		else if (strcmp(com, "empty") == 0) {
			printf("%d\n", (siz() == 0 ? 1 : 0));
		}
		else if (strcmp(com, "top") == 0) {
			printf("%d\n", top());
		}
	}

}