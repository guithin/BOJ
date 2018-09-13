#include<stdio.h>

int dp[50] = { 1, 0, 3 };

int ti(int cur) {
	if (dp[cur] != 0)return dp[cur];
	dp[cur] += dp[2] * ti(cur - 2);
	for (int i = 2; i <= cur/2; i++) {
		dp[cur] += 2 * ti(cur - 2 * i);
	}
	return dp[cur];
}

int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", ti(n));
	return 0;
}