#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

ll N, L, R;
ll cache[110][110][110];

ll dp(ll n, ll l, ll r) {
	if (n == 1) {
		if (l == 1 && r == 1) return 1;
		else return 0;
	}
	ll& ret = cache[n][l][r];
	if (ret != -1) return ret;
	ret = ((dp(n - 1, l - 1, r) + dp(n - 1, l, r - 1)) % mod + (dp(n - 1, l, r)*(n - 2)) % mod) % mod;
	return ret;
}

int main() {
	memset(cache, 0xff, sizeof(cache));
	scanf("%lld %lld %lld", &N, &L, &R);
	printf("%lld\n", dp(N, L, R));
}