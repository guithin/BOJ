#include<stdio.h>

int n, m, cur;
int dp[1010][1010][3];
char map[1010][1010];

int main() {
	scanf("%d %d %d", &n, &m, &cur);
	for (int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 'J')map[i][j] = 0;
			if (map[i][j] == 'O')map[i][j] = 1;
			if (map[i][j] == 'I')map[i][j] = 2;
			dp[i][j][map[i][j]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] += dp[i][j - 1][k];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] += dp[i - 1][j][k];
			}
		}
	}
	for (int i = 1; i <= cur; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a > c || b > d || a <= 0 || b <= 0) {
			while (1) {

			}
		}
		for (int j = 0; j < 3; j++) {
			printf("%d ", dp[c][d][j] - dp[a - 1][d][j] - dp[c][b - 1][j] + dp[a - 1][b - 1][j]);
		}
		printf("\n");
	}
	return 0;
}