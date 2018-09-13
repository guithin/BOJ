#include<stdio.h>
#include<memory.h>

int main() {
	int n;
	scanf("%d", &n);
	int input[1010] = { 0 };
	int dp[1010] = { 0 };
	memset(dp, 60, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= input[i]; j++) {
			if (i + j > 1000)continue;
			if (dp[i + j] > dp[i] + 1) {
				dp[i + j] = dp[i] + 1;
			}
		}
	}
	if (dp[n] < dp[0])printf("%d\n", dp[n]);
	else printf("-1\n");
	return 0;
}