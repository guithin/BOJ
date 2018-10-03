#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<ll>vec[500010];
ll sp[500010];
ll cnt[500010];
ll inp[500010];
ll temp = 1;

ll high = 1;
ll tree[1100000];
ll lazy[1100000];

void lazyup(ll node) {
	if (node >= high) {
		tree[node] += lazy[node];
	}
	else {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void back(ll x) {
	sp[x] = temp++; cnt[x]++;
	for (ll i = 0; i < vec[x].size(); i++) {
		back(vec[x][i]); cnt[x] += cnt[vec[x][i]];
	}
}

void update(ll node, ll nl, ll nr, ll fl, ll fr, ll c) {
	lazyup(node);
	if (fl <= nl && nr <= fr) {
		lazy[node] += c; return;
	}
	if (fr < nl || nr < fl)return;
	ll mid = (nl + nr) / 2;
	update(node * 2, nl, mid, fl, fr, c);
	update(node * 2 + 1, mid + 1, nr, fl, fr, c);
}

ll searchTree(ll node, ll nl, ll nr, ll fl) {
	lazyup(node);
	if (nl == fl && nr == fl)return tree[node];
	ll mid = (nl + nr) / 2;
	if (nl <= fl && fl <= mid)return searchTree(node * 2, nl, mid, fl);
	else return searchTree(node * 2 + 1, mid + 1, nr, fl);
}

int main() {
	scanf("%lld %lld", &n, &m);
	while (high < n)high <<= 1;
	for (ll i = 1; i <= n; i++) {
		if (i == 1) {
			scanf("%lld", inp + 1);
			continue;
		}
		ll b;
		scanf("%lld %lld", inp + i, &b);
		//
		vec[b].push_back(i);
	}
	back(1);
	for (ll i = 1; i <= n; i++) {
		tree[high + sp[i] - 1] = inp[i];
	}
	for (ll i = 1; i <= m; i++) {
		scanf(" ");
		char c = getchar();
		if (c == 'p') {
			ll a, b; scanf("%lld %lld", &a, &b);
			update(1, 1, high, sp[a] + 1, sp[a] + cnt[a] - 1, b);
		}
		else {
			ll a; scanf("%lld", &a);
			printf("%lld\n", searchTree(1, 1, high, sp[a]));
		}
	}
	return 0;
}