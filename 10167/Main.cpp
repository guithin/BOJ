#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;
typedef long long ll;

struct pos {
	ll x, y, w;
	pos() {};
	pos(ll a, ll b, ll c) {
		x = a; y = b; w = c;
	}
	bool operator<(const pos&io)const {
		return y < io.y;
	}
};

struct fac {
	ll lm, rm, sum, m;
	fac() {};
	fac(ll a, ll b, ll c) {
		lm = a; rm = b; sum = c;
	}
};

ll n;
ll high = 1;
pos inp[3010];
vector<ll>srtx;
vector<ll>srty;
fac tree[12010];

void update(pos now) {
	ll node = high + now.x - 1;
	tree[node].lm += now.w;
	tree[node].rm += now.w;
	tree[node].sum += now.w;
	tree[node].m += now.w;
	while (node >>= 1) {
		tree[node].lm = max(tree[node * 2].lm, tree[node * 2].sum + tree[node * 2 + 1].lm);
		tree[node].rm = max(tree[node * 2 + 1].rm, tree[node * 2 + 1].sum + tree[node * 2].rm);
		tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
		tree[node].m = max({ tree[node * 2].m, tree[node * 2 + 1].m, tree[node].lm, tree[node].rm });
		tree[node].m = max({ tree[node].m, tree[node * 2].rm, tree[node * 2].rm + tree[node * 2 + 1].lm, tree[node * 2 + 1].lm });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while (high < n)high <<= 1;

	for (ll i = 1; i <= n; i++) {
		cin >> inp[i].x >> inp[i].y >> inp[i].w;
		srtx.push_back(inp[i].x);
		srty.push_back(inp[i].y);
	}
	sort(srtx.begin(), srtx.end());
	sort(srty.begin(), srty.end());
	srtx.resize(unique(srtx.begin(), srtx.end()) - srtx.begin());
	srty.resize(unique(srty.begin(), srty.end()) - srty.begin());
	for (ll i = 1; i <= n; i++) {
		inp[i].x = lower_bound(srtx.begin(), srtx.end(), inp[i].x) - srtx.begin() + 1;
		inp[i].y = lower_bound(srty.begin(), srty.end(), inp[i].y) - srty.begin() + 1;
	}
	sort(inp + 1, inp + 1 + n);

	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (inp[i].y == inp[i - 1].y)continue;
		memset(tree, 0, sizeof(tree));
		for (ll j = i; j <= n; j++) {
			update(inp[j]);
			if (inp[j].y == inp[j + 1].y)continue;
			if (ans < tree[1].m)
				ans = tree[1].m;
//			ans = max({ ans, tree[1].lm, tree[1].rm, tree[2].rm, tree[3].lm, tree[2].rm + tree[3].lm, tree[3].lm });
		}
	}
	cout << ans << '\n';
	return 0;
}