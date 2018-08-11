#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, L, R;

ll cp[22][22];

ll dp[22][22][22];

ll combi(ll n, ll r) {
	return cp[n][r];
}

ll func(ll n, ll l, ll r) {
	if (dp[n][l][r] != -1)return dp[n][l][r];
	if (n + 1 < l + r || l + r < 3)return dp[n][l][r] = 0LL;
	if (n && (!l || !r))return dp[n][l][r] = 0LL;
	dp[n][l][r] = 0LL;
	for (ll i = 0; i <= n; i++) {
		ll left = i;
		ll right = n - i - 1;
		ll a = 0, b = 0;
		for (ll j = 0; j <= left; j++) {
			a += func(left, l - 1, j);
		}
		for (ll j = 0; j <= right; j++) {
			b += func(right, j, r - 1);
		}
		dp[n][l][r] += a * b * combi(n - 1, left);
	}
	return dp[n][l][r];
}

int main() {
	cp[0][0] = 1;
	for (ll i = 1; i <= 20; i++) {
		cp[i][0] = 1;
		for (ll j = 1; j <= i; j++) {
			cp[i][j] = cp[i - 1][j - 1] + cp[i - 1][j];
		}
	}
	memset(dp, 0xff, sizeof(dp));
	dp[0][0][0] = 1;
	dp[1][1][1] = 1;
	ll t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld %lld", &N, &L, &R);
		printf("%lld\n", func(N, L, R));
	}
	return 0;
}