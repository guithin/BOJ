#include<stdio.h>
typedef long long ll;

ll input[500010] = { 0 };
bool chk[500010] = { 0 };
ll len[500010] = { 0 };
ll n, a, b, c, d;

ll find(ll x, ll f, ll cnt) {
	if (chk[x])return 1;
	if (input[x] == f)return cnt;
	chk[x] = true;
	return find(input[x], f, cnt + 1);
}

ll gcd(ll a, ll b) {
	return !(a%b) ? b : gcd(b, a%b);
}

ll function(ll a, ll b) {
	return (a / gcd(a, b))*b;
}

int main() {
	scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &input[i]);
	}
	ll lcm = 1;
	for (ll i = 1 + c; i <= n - d; i++) {
		len[i] = find(i, i, 1);
		lcm = function(lcm, len[i]);
	}
	ll count = 0;
	for (ll i = 1; i <= b; i += lcm) {
		if (i < a)continue;
		count++;
	}
	printf("%lld\n", count);
	return 0;
}