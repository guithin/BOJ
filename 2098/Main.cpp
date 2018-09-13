#include<stdio.h>
#include<memory.h>

const int inf = 100000000;
int n;
int map[20][20] = { 0 };
int dp[70000][20] = { 0 };
int ans = inf;

int func(int end, int bit) {
	if (bit == 0) {
		return map[1][end];
	}
	if (dp[bit][end] != dp[0][19])return dp[bit][end];

	int mini = inf;
	for (int i = 1; i <= n; i++) {
		if (bit&(1 << (i - 1))) {
			int temp = func(i, bit - (1 << (i - 1)));
			if (mini > temp + map[i][end])
				mini = temp + map[i][end];
		}
	}
	if (mini >= inf)return inf;
	if (dp[bit][end] > mini)
		dp[bit][end] = mini;
	return dp[bit][end];
}

int main() {
	memset(dp, 40, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)map[i][j] = inf;
		}
	}
	for (int i = 2; i <= n; i++) {
		int b = ((1 << n) - 1) - (1 | (1 << (i - 1)));
		if (func(i, b) + map[i][1] < ans) {
			ans = func(i, b) + map[i][1];
		}
	}
	printf("%d\n", ans);
	return 0;
}