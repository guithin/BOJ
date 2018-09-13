#include<stdio.h>

int main() {
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 1; i <= 50; i++) {
		if (n - 2 * i >= 4) {
			count += ((n - 2 * i) / 2) - 1;
		}
		else
			break;
	}
	printf("%d\n", count);
	return 0;
}