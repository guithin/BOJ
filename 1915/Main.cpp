#include<stdio.h>

int n, m;
int map[1010][1010];
int dp[1010][1010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
			dp[i][j] = map[i][j];
			dp[i][j] += dp[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] += dp[i][j - 1];
		}
	}
	int maxi = 0;
	int temp = n > m ? n : m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= temp; k++) {
				if (i - k < 0 || j - k < 0)continue;
				if (dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] == k*k)
					if (maxi < k*k)maxi = k*k;
			}
		}
	}
	printf("%d\n", maxi);
	return 0;
}