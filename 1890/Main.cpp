#include<stdio.h>
typedef long long ll;
ll n;
ll map[110][110];
ll dp[110][110];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			scanf("%lld", &map[i][j]);
		}
	}
	dp[1][1] = 1;
	map[n][n] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i + map[i][j] <= n)
				dp[i + map[i][j]][j] += dp[i][j];
			if (j + map[i][j] <= n)
				dp[i][j + map[i][j]] += dp[i][j];
		}
	}
	printf("%lld\n", dp[n][n]);
	return 0;
}