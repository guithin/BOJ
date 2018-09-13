#include<stdio.h>
#include<memory.h>

int inp[510] = {};
int dp[510][510] = {};
int sum[510][510] = {};

int func(int sp, int n) {
	if (dp[sp][n] != -1)return dp[sp][n];
	int mini = 100000000;
	for (int i = 1; i < n; i++) {
		int temp = sum[i][sp] + sum[n - i][sp + i];
		if (i != 1)temp += func(sp, i);
		if ((n - i) != 1)temp += func(sp + i, n - i);

		if (temp < mini) {
			mini = temp;
		}
	}

	return dp[sp][n] = mini;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(inp, 0, sizeof(inp));
		memset(dp, 0xff, sizeof(dp));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", inp + i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - i + 1; j++) {
				sum[i][j] = sum[i - 1][j] + inp[i + j - 1];
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[i][1] = inp[i];
		}
		printf("%d\n", func(1, n));
	}
	return 0;
}