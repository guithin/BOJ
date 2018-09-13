#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n / 3; i++) {
		for (int j = 0; j <= n / 5; j++) {
			if (3 * i + 5 * j == n) {
				printf("%d\n", i + j);
				return 0;
			}
			else if (3 * i + 5 * j > n)break;
		}
	}
	printf("-1\n");
	return 0;
}