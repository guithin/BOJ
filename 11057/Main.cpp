#include<stdio.h>

int lv[15][1010] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 0; j < 10; j++) {
				lv[j][i] = 1;
			}
			continue;
		}
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				lv[j][i] += lv[k][i - 1];
				lv[j][i] %= 10007;
			}
		}
	}
/*	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", lv[j][i]);
		}
		printf("\n");
	}*/
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += lv[i][n];
		sum %= 10007;
	}
	printf("%lld\n", sum);
	return 0;
}