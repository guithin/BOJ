#include<stdio.h>
#include<algorithm>
typedef long long ll;

ll n, m, k;
ll tree[4000010] = { 0 };
ll lazy[4000010] = { 0 };
ll high = 1;

ll func(ll x1, ll y1, ll x2, ll y2) {
	if (y1 < x2 || x1 > y2)return 0;
	return std::min(y1, y2) - std::max(x1, x2) + 1;
}

void lazyup(ll node, ll nl, ll nr, ll fl, ll fr, ll c) {
	if (nr < fl || fr < nl)return;
	if (nl >= fl&&fr >= nr) {
		lazy[node] += c;
		return;
	}
	tree[node] += c * func(nl, nr, fl, fr);
	ll mid = (nl + nr) / 2;
	lazyup(node * 2, nl, mid, fl, fr, c);
	lazyup(node * 2 + 1, mid + 1, nr, fl, fr, c);
}

ll find(ll node, ll nl, ll nr, ll fl, ll fr) {
	if (nr < fl || fr < nl)return 0;
	if (nl >= fl&&fr >= nr)return tree[node] + lazy[node] * (nr - nl + 1);
	tree[node] += lazy[node] * (nr - nl + 1);
	lazy[node * 2] += lazy[node];
	lazy[node * 2 + 1] += lazy[node];
	lazy[node] = 0;
	ll mid = (nl + nr) / 2;
	return find(node * 2, nl, mid, fl, fr) + find(node * 2 + 1, mid + 1, nr, fl, fr);
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	while (n > high)high <<= 1;
	for (ll i = 0; i < n; i++) {
		scanf("%lld", tree + high + i);
	}
	for (ll i = high - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	for (ll i = 1; i <= m + k; i++) {
		ll mode;
		scanf("%lld", &mode);
		if (mode == 1) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			if (a > b)std::swap(a, b);
			lazyup(1, 1, high, a, b, c);
		}
		else {
			ll a, b;
			if (a > b)std::swap(a, b);
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", find(1, 1, high, a, b));
		}
	}
	return 0;
}