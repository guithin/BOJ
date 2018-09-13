#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pos {
	ll val, bit;
	pos() {};
	pos(ll a, ll b) {
		val = a; bit = b;
	}
	bool operator<(const pos&io)const {
		return val < io.val;
	}
};

ll n;
ll inp[2][40];
vector<pos>s[2][20];
vector<pos>d[2][20];

void back(ll now, ll lim, ll cnt, ll sum, ll temp) {
	if (now == lim + 1) {
		if (lim == n) {
			s[1][cnt].push_back(pos(sum, temp));
		}
		else {
			s[0][cnt].push_back(pos(sum, temp));
		}
		return;
	}
	back(now + 1, lim, cnt + 1, sum + inp[0][now], temp);
	back(now + 1, lim, cnt, sum - inp[1][now], temp | (1ll << (now - 1)));
}

void func(ll &a1, ll &b1, ll &a2, ll &b2) {
	ll z = a1, x = a2;
	for (ll i = 1; i <= n / 2; i++) {
		if ((z & 1) == (x & 1)) {
			z >>= 1; x >>= 1;
		}
		else if (z & 1) {
			a1 = a2; b1 = b2;
		}
		else return;
	}
	z = b1; x = b2;
	z >>= n / 2; x >>= n / 2;
	for (ll i = 1; i <= n / 2; i++) {
		if (z & 1 == x & 1) {
			z >>= 1; x >>= 1;
		}
		else if (z & 1) {
			a1 = a2; b1 = b2;
		}
		else return;
	}
}

ll f(ll bit1, ll bit2) {
	ll z = bit1, x = bit2;
	z >>= n / 2; x >>= n / 2;
	for (int i = 1; i <= n / 2; i++) {
		if ((z & 1) == (x & 1)) {
			z >>= 1; x >>= 1;
		}
		else if (z & 1) return bit2;
		else return bit1;
	}
	return bit1;
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &inp[0][i]);
	}
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &inp[1][i]);
	}
	ll a = n / 2;
	ll q = 0, w = 0;
	ll ans = 9000000000000000000;
	back(1, a, 0, 0, 0);
	back(a + 1, n, 0, 0, 0);
	for (ll i = 0; i <= n / 2; i++) {
		sort(s[1][i].begin(), s[1][i].end());
		d[1][i].push_back(s[1][i][0]);
		for (ll j = 1; j < s[1][i].size(); j++) {
			if (d[1][i][d[1][i].size() - 1].val == s[1][i][j].val) {
				d[1][i][d[1][i].size() - 1].bit = f(s[1][i][j].bit, d[1][i][d[1][i].size() - 1].bit);
			}
			else {
				d[1][i].push_back(s[1][i][j]);
			}
		}
	}
	for (ll i = 0; i <= n / 2; i++) {
		for (ll j = 0; j < s[0][i].size(); j++) {
			pos t = s[0][i][j];
			ll idx = lower_bound(d[1][n / 2 - i].begin(), d[1][n / 2 - i].end(), pos(-t.val, 0)) - d[1][n / 2 - i].begin();
			vector<pos>&temp = d[1][n / 2 - i];
			if (idx<temp.size() && ans > abs(temp[idx].val + t.val)) {
				ans = abs(temp[idx].val + t.val);
				w = temp[idx].bit; q = t.bit;
			}
			else if (idx < temp.size() && ans == abs(temp[idx].val + t.val)) {
				func(q, w, t.bit, temp[idx].bit);
			}
			if (idx&&ans > abs(temp[idx - 1].val + t.val)) {
				ans = abs(temp[idx - 1].val + t.val);
				w = temp[idx - 1].bit; q = t.bit;
			}
			else if (idx&&ans == abs(temp[idx - 1].val + t.val)) {
				func(q, w, t.bit, temp[idx - 1].bit);
			}
		}
	}
	w >>= n / 2;
	for (ll i = 1; i <= n / 2; i++) {
		printf("%lld ", (q & 1) + 1);
		q >>= 1;
	}
	for (ll i = 1; i <= n / 2; i++) {
		printf("%lld ", (w & 1) + 1);
		w >>= 1;
	}
	return 0;
}