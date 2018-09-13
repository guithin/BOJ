#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum += i + j;
		}
	}
	printf("%d\n", sum);
	return 0;
}