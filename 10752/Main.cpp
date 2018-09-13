#include<stdio.h>

int n, m;
int map[30][30] = { 0 };
int dp[30][30] = { 0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" ");
		for (int j = 1; j <= m; j++) {
			char c = getchar();
			map[i][j] = c == 'R' ? 1 : 0;
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = i + 1; k <= n; k++) {
				for (int l = j + 1; l <= m; l++) {
					if (map[i][j] != map[k][l])
						dp[k][l] +=dp[i][j];
				}
			}
		}
	}
	printf("%d\n", dp[n][n]);
	return 0;
}