#include<stdio.h>

int sqr(int x, int y) {
	int r = 1;
	for (int i = 1; i <= y; i++) {
		r *= x;
	}
	return r;
}

int main() {
	char str[50] = { 0 };
	int stack[50] = { 0 };
	int small = 0;
	int big = 0;
	int sum = 0;
	int idx = 0;
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(') {
			stack[idx] = '(';
			idx++;
			small++;
		}
		else if (str[i] == ')') {
			if (stack[idx - 1] == '(') {
				stack[idx - 1] = 0;
				idx--;
				small--;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		else if (str[i] == '[') {
			stack[idx] = '[';
			big++;
			idx++;
		}
		else if (str[i] == ']') {
			if (stack[idx - 1] == '[') {
				stack[idx - 1] = 0;
				idx--;
				big--;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		if (small < 0 || big < 0) {
			printf("0\n");
			return 0;
		}
	}
	if (small != 0 || big != 0) {
		printf("0\n");
		return 0;
	}
	int temp = 1;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(') {
			temp *= 2;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				sum += temp;
			}
			temp /= 2;
		}
		else if (str[i] == '[') {
			temp *= 3;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				sum += temp;
			}
			temp /= 3;
		}
	}
	printf("%d\n", sum);
	return 0;
}