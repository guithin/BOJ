#include<stdio.h>
typedef long long ll;

struct pos {
	ll val, num;
	pos() {};
	pos(ll a, ll b) {
		val = a;
		num = b;
	}
};

ll t, n;
pos inp[110];
ll dp[110][10010];

int main() {
	scanf("%lld %lld", &t, &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &inp[i].val, &inp[i].num);
	}
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= t; j++) {
			if (dp[i - 1][0] == 0)continue;
			for (ll k = 0; k <= inp[i].num; k++) {
				if (j + inp[i].val*k > t)break;
				dp[i][j + inp[i].val*k] += dp[i - 1][j];
			}
		}
	}
	printf("%lld\n", dp[n][t]);
	return 0;
}