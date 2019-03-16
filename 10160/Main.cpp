#include<stdio.h>
typedef long long ll;

ll mod = 1000000009;
ll dp[1000010];

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		dp[i] = (dp[i - 1] * k) % mod;
		if (i >= 5)dp[i] -= (dp[i - 5] * 2) % mod;
		if (i >= 7)dp[i] += (dp[i - 7]);
		dp[i] = (dp[i] + mod) % mod;
	}
	printf("%lld\n", dp[n]);
	return 0;
}