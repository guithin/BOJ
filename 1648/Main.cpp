#include<stdio.h>
#include<algorithm>

int n, m;
int dp[20][33000] = { 0 };

void back(int cur, int bit, int now, int j) {
	if (cur == n + 1) {
		dp[now + 1][bit] += dp[now][j] % 9901;
		dp[now + 1][bit] %= 9901;
		return;
	}
	if (cur == n + 2)return;
	if (!(j&(1 << cur))) {
		back(cur + 1, bit | (1 << cur), now, j);
	}
	else {
		if (j&(1 << (cur + 1))) {
			back(cur + 2, bit | (1 << cur) | (1 << (cur + 1)), now, j);
		}
		back(cur + 1, bit, now, j);
	}
}

void init(int cur, int bit) {
	if (cur == n + 1) {
		dp[1][bit] = 1;
		return;
	}
	if (cur + 1 <= n) {
		init(cur + 2, bit | (1 << cur) | (1 << (cur + 1)));
	}
	init(cur + 1, bit);
}

int main() {
	scanf("%d %d", &n, &m);
	init(1, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (1 << (n + 1)) - 1; j++) {
			if (dp[i][j]) {
				back(1, 0, i, j);
			}
		}
	}
	printf("%d\n", dp[m][(1 << (n + 1)) - 2]);
	return 0;
}