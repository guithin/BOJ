#include<stdio.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int a[5];
	int b[5];
	int c[110] = { 0 };
	for (int i = 1; i <= 3; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = a[i]; j < b[i]; j++) {
			c[j]++;
		}
	}
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (c[i] == 1)
			sum += A;
		else if (c[i] == 2)
			sum += B * 2;
		else if (c[i] == 3)
			sum += C * 3;
	}
	printf("%d\n", sum);
	return 0;
}