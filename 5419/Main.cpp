#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;
typedef long long ll;

struct pos {
	ll x, y;
	pos() {};
	pos(ll a, ll b) {
		x = a; y = b;
	}
	bool operator<(const pos&io)const {
		if (x == io.x)
			return y < io.y;
		return x > io.x;
	}
};

ll n;
vector<pos>vec;
vector<ll>cmpx;
vector<ll>cmpy;
ll tree[300000];
ll high = 1;
ll ans;

ll find(ll node, ll nl, ll nr, ll fl) {
	if (!tree[node])return 0;
	if (nr <= fl)return tree[node];
	if (nl > fl)return 0;
	ll mid = (nr + nl) / 2;
	return find(node * 2, nl, mid, fl) + find(node * 2 + 1, mid + 1, nr, fl);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (high < 75000)high <<= 1;
	ll t;
	cin >> t;
	while (t--) {
		memset(tree, 0, sizeof(tree));
		cmpx.clear();
		cmpy.clear();
		vec.clear();
		ans = 0;

		cin >> n;
		
		for (ll i = 1; i <= n; i++) {
			ll a, b;
			cin >> a >> b;
			vec.push_back(pos(a, b));
			cmpx.push_back(a);
			cmpy.push_back(b);
		
		}
		sort(cmpx.begin(), cmpx.end());
		sort(cmpy.begin(), cmpy.end());
		
		cmpx.resize(unique(cmpx.begin(), cmpx.end()) - cmpx.begin());
		cmpy.resize(unique(cmpy.begin(), cmpy.end()) - cmpy.begin());
		
		for (auto &it : vec) {
			it.x = lower_bound(cmpx.begin(), cmpx.end(), it.x) - cmpx.begin() + 1;
			it.y = lower_bound(cmpy.begin(), cmpy.end(), it.y) - cmpy.begin() + 1;
		}
		
		sort(vec.begin(), vec.end());
		
		for (auto &it : vec) {
			ans += find(1, 1, high, it.y);
			for (ll i = high + it.y - 1; i >= 1; i >>= 1)
				tree[i]++;
		}
		
		cout << ans << '\n';
	};
	return 0;
}