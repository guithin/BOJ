#include<stdio.h>
#include<algorithm>
#include<vector>

typedef long long ll;

struct pos {
	ll s, e, y;
	pos() {};
	pos(ll a, ll b, ll c) {
		s = a; e = b; y = c;
	}
	bool operator<(const pos&io)const {
		return y < io.y;
	}
};

ll n;
pos inp[50010];
std::vector<ll>cola;
ll segtree[1000010] = { 0 };
ll lazy[1000010] = { 0 };
ll high = 1;

void lazyup(ll node, ll nl, ll nr, ll fl, ll fr) {
	if (lazy[node]) {
		segtree[node] = (nr - nl + 1);
		if (nl != nr) {
			lazy[node * 2] = 1;
			lazy[node * 2 + 1] = 1;
		}
		lazy[node] = 0;
	}
	if (nr < fl || fr < nl) return;
	if (nl >= fl&&fr >= nr) {
		segtree[node] = (nr - nl + 1);
		if (nl != nr) {
			lazy[node*2] = 1;
			lazy[node * 2 + 1] = 1;
		}
		return;
	}
	ll mid = (nl + nr) / 2;
	lazyup(node * 2, nl, mid, fl, fr);
	lazyup(node * 2 + 1, mid + 1, nr, fl, fr);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll find(ll node, ll nl, ll nr, ll fl, ll fr) {
	if (lazy[node]) {
		segtree[node] = (nr - nl + 1);
		lazy[node * 2] = 1;
		lazy[node * 2 + 1] = 1;
		lazy[node] = 0;
	}
	if (fl <= nl&&nr <= fr) {
		return segtree[node];
	}
	if (nr < fl || fr < nl) return 0;
	ll mid = nl + nr >> 1;
	return find(node * 2, nl, mid, fl, fr) + find(node * 2 + 1, mid + 1, nr, fl, fr);
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		ll temp1, temp2;
		scanf("%lld %lld %lld", &temp1, &inp[i].y, &temp2);
		inp[i].s = -temp1*temp2 - temp2;
		inp[i].e = -temp1*temp2;
		cola.push_back(inp[i].s);
		cola.push_back(inp[i].e);
	}
	std::sort(inp + 1, inp + 1 + n);
	std::sort(cola.begin(), cola.end());
	cola.erase(std::unique(cola.begin(), cola.end()), cola.end());
	high = cola.size()+1;
	for (ll i = 1; i <= n; i++) {
		inp[i].s = (std::lower_bound(cola.begin(), cola.end(), inp[i].s) - cola.begin()) + 1;
		inp[i].e = (std::lower_bound(cola.begin(), cola.end(), inp[i].e) - cola.begin());
	}
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		ll qwer = find(1, 1, high, inp[i].s, inp[i].e);
		if (qwer != inp[i].e - inp[i].s + 1) {
			cnt++;
			lazyup(1, 1, high, inp[i].s, inp[i].e);
		}
	}
	printf("%lld\n", cnt);
	return 0;
}