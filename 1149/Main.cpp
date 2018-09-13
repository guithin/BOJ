#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int R[1010] = { 0 };
int G[1010] = { 0 };
int B[1010] = { 0 };
int dp[1010][5] = { 0 };

int func(int cur, int n) {
	if (dp[cur][n] != -1)return dp[cur][n];
	if (n == 1) {
		dp[cur][n] = min(func(cur - 1, 2), func(cur - 1, 3)) + R[cur];
	}
	else if (n == 2) {
		dp[cur][n] = min(func(cur - 1, 1), func(cur - 1, 3)) + G[cur];
	}
	else {
		dp[cur][n] = min(func(cur - 1, 1), func(cur - 1, 2)) + B[cur];
	}
	return dp[cur][n];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d %d %d", R + i, G + i, B + i);
	memset(dp, -1, sizeof(dp));
	dp[1][1] = R[1];
	dp[1][2] = G[1];
	dp[1][3] = B[1];
	printf("%d\n", min(func(n, 1), min(func(n, 2), func(n, 3))));
	return 0;
}