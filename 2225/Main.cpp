#include<stdio.h>
typedef long long ll;

const long long mod = 1000000000;

ll N, K;
ll dp[210][210] = { 0 };

int main() {
	scanf("%lld %lld", &N, &K);
	for (ll i = 1; i <= K; i++) {
		dp[i][0] = 1;
	}
	for (ll i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	printf("%lld\n", dp[K][N]);
	return 0;
}