#include<bits/stdc++.h>
using namespace std;

int inp[100010];
int dp[100010][5][5];

int cost[5][5] = { {
		0, 2, 2, 2, 2},{
		0, 1, 3, 4, 3},{
		0, 3, 1, 3, 4},{
		0, 4, 3, 1, 3},{
		0, 3, 4, 3, 1} };

int main() {
	int n = 0, temp;
	while (1) {
		scanf("%d", &temp);
		if (temp) {
			inp[++n] = temp;
		}
		else
			break;
	}
	memset(dp, 40, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (inp[i] != k)
					dp[i][inp[i]][k] = min(dp[i][inp[i]][k], dp[i - 1][j][k] + cost[j][inp[i]]);
				if (inp[i] != j) 
					dp[i][j][inp[i]] = min(dp[i][j][inp[i]], dp[i - 1][j][k] + cost[k][inp[i]]);
			}
		}
	}
	int mini = 1234567890;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			mini = min(mini, dp[n][i][j]);
		}
	}
	printf("%d\n", mini);
	return 0;
}