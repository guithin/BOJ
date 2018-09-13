#include<stdio.h>
#include<memory.h>

const int mod = 1000000007;

int n, m, q;
int tot = 0;
int map[1000][1000] = { 0 };
int num[600000] = { 0 };
int dp[1000][1000] = { 0 };

int func(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];
	if (x == 1 && y != 1)return 0;
	if (x != 1 && y == 1)return 0;
	if (x == 1 && y == 1)return 1;
	int sum = 0;
	for (int i = 1; i < x; i++) {
		for (int j = 1; j < y; j++) {
			if (map[i][j] != map[x][y]) {
				sum += func(i, j);
				sum %= mod;
			}
		}
	}
	return dp[x][y] = sum;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dp[1][1] = 1;

	printf("%d\n", func(n, n));
	return 0;
}