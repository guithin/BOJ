#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll sqr(ll x, ll y) {
	if (!y)return 1ll;
	if (y == 1)return x;
	ll temp = sqr(x, y / 2);
	if (y & 1)return (((temp*temp) % mod)*x) % mod;
	return (temp*temp) % mod;
}

int main() {
	ll n, r;
	scanf("%lld %lld", &n, &r);
	ll ja = 1, mo = 1;
	for (ll i = 2; i <= n; i++) {
		ja *= i;
		ja %= mod;
	}
	for (ll i = 2; i <= r; i++) {
		mo *= i;
		mo %= mod;
	}
	for (ll i = 2; i <= n - r; i++) {
		mo *= i;
		mo %= mod;
	}
	printf("%lld\n", (ja*sqr(mo, mod - 2)) % mod);
	return 0;
}