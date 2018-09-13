#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

struct pos {
	ll l, r;
	pos() {};
	pos(ll a, ll b) {
		l = a; r = b;
	}
};

ll n;
ll high = 1;
vector<pos>vec;
vector<int>srt;
ll tree[66000];
ll lazy[66000];
bool chk[10010] = { 1, 0 };

void lazyup(ll node) {
	if (lazy[node]) {
		tree[node] = lazy[node];
		if (node < high) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(ll node, ll nl, ll nr, ll fl, ll fr, ll c) {
	lazyup(node);
	if (fl <= nl && nr <= fr) {
		lazy[node] = c;
		return;
	}
	if (nr < fl || fr < nl) {
		return;
	}
	ll mid = (nl + nr) / 2;
	update(node * 2, nl, mid, fl, fr, c);
	update(node * 2 + 1, mid + 1, nr, fl, fr, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (high < 20000)high <<= 1;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll a, b;
		cin >> a >> b;
		vec.push_back(pos(a, b));
		srt.push_back(a);
		srt.push_back(b);
	}
	sort(srt.begin(), srt.end());
	srt.resize(unique(srt.begin(), srt.end()) - srt.begin());
	for (auto &it : vec) {
		it.l = lower_bound(srt.begin(), srt.end(), it.l) - srt.begin() + 1;
		it.r = lower_bound(srt.begin(), srt.end(), it.r) - srt.begin() + 1;
	}
	for (ll i = 0; i < vec.size(); i++) {
		update(1, 1, high, vec[i].l, vec[i].r, i + 1);
	}
	for (ll i = 1; i < high * 2; i++) {
		lazyup(i);
	}
	ll cnt = 0;
	for (ll i = high; i < high * 2; i++) {
		if (!chk[tree[i]]) {
			cnt++;
			chk[tree[i]] = true;
		}
	}
	cout << cnt << '\n';
	return 0;
}