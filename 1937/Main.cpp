#include<stdio.h>

typedef long long ll;

ll map[510][510] = { 0 };
ll dp[510][510] = { 0 };

ll dx[4] = { 0,0,1,-1 };
ll dy[4] = { 1,-1,0,0 };

ll func(ll x, ll y) {
	if (dp[x][y] != 0)return dp[x][y];
	ll maxi = 1;
	for (ll i = 0; i < 4; i++) {
		if (map[x][y] < map[x + dx[i]][y + dy[i]]) {
			if (maxi < func(x + dx[i], y + dy[i]) + 1)maxi = func(x + dx[i], y + dy[i]) + 1;
		}
	}
	return dp[x][y] = maxi;
}

int main() {
	ll n;
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			scanf("%lld", &map[i][j]);
		}
	}
	ll maxi = -1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (maxi < func(i, j))maxi = func(i, j);
		}
	}
	printf("%lld\n", maxi);
	return 0;
}