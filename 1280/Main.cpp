#include<stdio.h>
typedef long long ll;

ll n;
ll high = 1;
ll inp[200010] = { 0 };
ll tree[1000010] = { 0 };
ll tree2[1000010] = { 0 };

const ll mod = 1000000007;

ll absx(ll x) {
	return x > 0 ? x : -x;
}

ll find(ll node, ll nl, ll nr, ll fl) {
	if (nr == nl&&nr == fl)return 0;
	if (nr < fl || nl > fl) {
		return absx(tree2[node]*fl - tree[node]);
	}
	ll mid = (nr + nl) / 2;
	return (find(node * 2, nl, mid, fl) + find(node * 2 + 1, mid + 1, nr, fl)) % mod;
}

int main() {
	scanf("%lld", &n);
	while (high < 200000) {
		high <<= 1;
	}
	long long ans = 1;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
		inp[i]++;
		ll now = find(1, 1, high, inp[i]);
		if(i - 1)
			ans *= now;
		ans %= mod;
		for (ll j = high + inp[i] - 1; j >= 1; j /= 2) {
			tree[j] += inp[i];
		}
		for (ll j = high + inp[i] - 1; j >= 1; j /= 2) {
			tree2[j]++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}