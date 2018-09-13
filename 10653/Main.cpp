#include<stdio.h>
#include<algorithm>
#include<memory.h>

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a; y = b;
	}
};

int absx(int x) {
	return x > 0 ? x : -x;
}

int n, k;
int dp[510][510] = { 0 };
pos inp[510];

int main() {
	memset(dp, 40, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inp[i].x, &inp[i].y);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i - 1; j++) {
			dp[i][j] = dp[i - 1][j] + absx(inp[i].x - inp[i - 1].x) + absx(inp[i].y - inp[i - 1].y);
			for (int kk = 1; kk <= j + 1; kk++) {
				dp[i][j] = std::min(dp[i][j], dp[i - kk][j - kk + 1] + absx(inp[i].x - inp[i - kk].x) + absx(inp[i].y - inp[i - kk].y));
			}
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}