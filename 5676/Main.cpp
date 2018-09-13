#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef long long ll;

struct segment_tree {
	typedef long long ll;
	ll n;
	ll high;
	ll *tree;
	ll noot;
	ll(*func)(ll, ll);
	void setup() {
		high = 1;
		while (n > high)high <<= 1;
		for (ll i = 0; i < n; i++) {
			tree[high + i] = tree[i];
			tree[i] = noot;
		}
		for (ll i = high - 1; i >= 1; i--) {
			tree[i] = func(tree[i * 2], tree[i * 2 + 1]);
		}
	}
	ll find(ll node, ll nl, ll nr, ll fl, ll fr) {
		if (nl > fr || nr < fl)return noot;
		if (nl >= fl&&nr <= fr)return tree[node];
		ll mid = (nl + nr) / 2;
		ll ret = func(find(node * 2, nl, mid, fl, fr), find(node * 2 + 1, mid + 1, nr, fl, fr));
		return ret;
	}
	ll find_val(ll a, ll b) {
		return find(1, 1, high, a, b);
	}
	void change_val(ll a, ll b) {
		ll temp = high + a + -1;
		tree[temp] = b;
		for (ll i = temp / 2; i >= 1; i >>= 1) {
			tree[i] = func(tree[i * 2], tree[i * 2 + 1]);
		}
	}
	segment_tree(ll num, ll *t, ll w, ll f(ll, ll)) {
		n = num;
		tree = t;
		func = *f;
		noot = w;
	}
};

ll F(ll a, ll b) {
	if (a*b == 0)return 0;
	return a*b > 0 ? 1 : -1;
}

int main() {
	while (1) {
		ll n, k;
		if (scanf("%lld %lld", &n, &k) != 2) break;
		ll *arr = (ll*)malloc(sizeof(ll)*n * 6);
		for (ll i = 1; i < 5 * n; i++)arr[i] = 1;
		for (ll i = 0; i < n; i++) {
			ll temp;
			scanf("%lld", &temp);
			if (!temp)arr[i] = 0;
			else arr[i] = temp > 0 ? 1 : -1;
		}
		segment_tree ans(n, arr, 1, F);
		ans.setup();
		for (ll i = 0; i < k; i++) {
			char fu[10] = { 0 };
			scanf("%s", fu);
			ll fff, ffff;
			scanf("%lld %lld", &fff, &ffff);
			if (fu[0] == 'C') {
				if (!ffff)
					ans.change_val(fff, 0);
				else
					ans.change_val(fff, ffff > 0 ? 1 : -1);
			}
			else {
				int fffff = ans.find_val(fff, ffff);
				if (!fffff)printf("0");
				else printf("%c", fffff > 0 ? '+' : '-');
			}
		}
		printf("\n");
	}
	return 0;
}