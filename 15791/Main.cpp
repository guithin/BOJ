#include<stdio.h>
typedef long long ll;

const ll mod = 1000000007;

ll sqr(ll x, ll y) {
	if (y == 1)return x;
	if (!y)return 1LL;
	ll temp = sqr(x, y / 2);
	if (y & 1)return (((temp*temp) % mod)*x) % mod;
	return (temp*temp) % mod;
}

int main() {
	ll n, r;
	scanf("%lld %lld", &n, &r);
	ll t = 1;
	for (ll i = 1; i <= n; i++) {
		t *= i; t %= mod;
	}
	ll k = 1;
	for (ll i = 1; i <= r; i++) {
		k *= i; k %= mod;
	}
	for (ll i = 1; i <= n - r; i++) {
		k *= i; k %= mod;
	}
	ll ans = (t*sqr(k, mod - 2)) % mod;
	printf("%lld\n", ans);
	return 0;
}