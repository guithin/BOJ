#include<stdio.h>

int main() {
	int n;
	long long lv[15][110] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		lv[i][1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int l = 0; l < 10; l++) {
			if (l == 0) {
				lv[l][i] = lv[l + 1][i - 1]%1000000000;
				continue;
			}
			lv[l][i] += lv[l + 1][i - 1]%1000000000;
			lv[l][i] += lv[l - 1][i - 1]%1000000000;
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += lv[i][n];
		if (sum > 1000000000)
			sum %= 1000000000;
	}
	printf("%lld\n", sum);
	return 0;
}