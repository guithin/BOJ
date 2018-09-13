#include<stdio.h>
#include<memory.h>
typedef long long ll;

ll n, m, high = 1;
ll tree[400010] = { 0 };

ll min(ll a, ll b) {
	return a > b ? b : a;
}

ll find(ll node, ll l, ll r, ll fl, ll fr) {
	if (r<fl || l>fr)return 123456789;
	if (fl <= l&&fr >= r)return tree[node];
	return min(find(node * 2, l, (l + r) / 2, fl, fr), find(node * 2 + 1, (l + r) / 2 + 1, r, fl, fr));
}

int main() {
	memset(tree, 40, sizeof(tree));
	scanf("%lld", &n);
	while (high < n)high <<= 1;
	for (ll i = 0; i < n; i++) {
		scanf("%lld", tree + high + i);
	}
	for (ll i = high - 1; i >= 1; i--) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
	scanf("%lld", &m);
	for (ll i = 1; i <= m; i++) {
		ll mode, a, b;
		scanf("%lld %lld %lld", &mode, &a, &b);
		if (mode == 1) {
			ll idx = a + high - 1;
			tree[idx] = b;
			idx >>= 1;
			for (; idx >= 1; idx >>= 1) {
				tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
			}
		}
		else {
			printf("%lld\n", find(1, 1, high, a, b));
		}
	}
	return 0;
}