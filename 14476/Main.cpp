#include<stdio.h>
#include<algorithm>
typedef long long ll;

ll n;
ll dp[1000010][2];
ll ff[1000010];
ll inp[1000010];

ll gcd(ll a, ll b) {
	return a%b ? gcd(b, a%b) : b;
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		ll temp;
		scanf("%lld", &temp);
		inp[i] = temp;
		if (i == 1) {
			dp[1][0] = temp;
		}
		else
			dp[i][0] = gcd(dp[i - 1][0], temp);
		if (i == 2) {
			dp[2][1] = temp;
			ff[2] = 1;
		}
		else if (i > 2) {
			ll fro = gcd(dp[i - 1][1], temp);
			ll bac = gcd(dp[i - 2][0], temp);
			if (fro > bac) {
				ff[i] = ff[i - 1];
				dp[i][1] = fro;
			}
			else {
				ff[i] = i - 1;
				dp[i][1] = bac;
			}
//			dp[i][1] = std::max(gcd(dp[i - 1][1], temp), gcd(dp[i - 2][0], temp));
		}

	}
	if (dp[n][0] == dp[n][1]) {
		printf("-1\n");
	}
	else {
		printf("%lld %lld\n", dp[n][1], inp[ff[n]]);
	}
	return 0;
}