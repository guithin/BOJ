#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct node {
	ll next[2];
	ll pro;
	node() {
		pro = 0;
		next[0] = next[1] = 0;
	}
};

ll n;
ll inp[100010];
vector<node>vec;

void lazy(ll idx, ll i) {
	if (vec[idx].pro) {
		if (vec[idx].pro&i) {
			swap(vec[idx].next[0], vec[idx].next[1]);
			vec[idx].pro -= i;
		}
		if (vec[idx].next[0])
			vec[vec[idx].next[0]].pro ^= vec[idx].pro;
		if (vec[idx].next[1])
			vec[vec[idx].next[1]].pro ^= vec[idx].pro;
		vec[idx].pro = 0;
	}
	return;
}

ll findMax(ll x) {
	ll idx = 0;
	ll r = 0;
	for (ll i = (1ll << 32); i; i >>= 1) {
		lazy(idx, i);
		ll nbit = (x&i) ? 1 : 0;
		if (vec[idx].next[nbit ^ 1]) {
			r |= i;
			idx = vec[idx].next[nbit ^ 1];
		}
		else if (vec[idx].next[nbit]) {
			idx = vec[idx].next[nbit];
		}
		else break;
	}
	return r;
}

void pushX(ll x) {
	ll idx = 0;
	for (ll i = (1ll << 32); i; i >>= 1) {
		lazy(idx, i);
		ll nbit = (x&i) ? 1 : 0;
		if (!vec[idx].next[nbit]) {
			vec[idx].next[nbit] = vec.size();
			vec.push_back(node());
		}
		idx = vec[idx].next[nbit];
	}
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		vec.clear();
		vec.push_back(node());
		scanf("%lld", &n);
		ll maxi = 0;

		for (ll i = 1; i <= n; i++) {
			ll temp;
			scanf("%lld", &temp);
			if (temp > maxi)maxi = temp;
			ll tt = findMax(temp);
			if (tt > maxi)maxi = tt;
			vec[0].pro ^= temp;
			pushX(temp);
		}
		printf("%lld\n", maxi);
	}

	return 0;
}