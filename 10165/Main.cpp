#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct pos {
	ll s, e, idx;
	pos() {};
	pos(ll a, ll b, ll c) {
		s = a; e = b; idx = c;
	}
	bool operator<(const pos&io)const {
		if (s == io.s)return e >io.e;
		return s < io.s;
	}
};

ll n, m;
vector<pos>vec;
ll chk[500010];

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= m; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if (a > b) {
			vec.push_back(pos(a - n, b, i));
			vec.push_back(pos(a, b + n, i));
		}
		else
			vec.push_back(pos(a, b, i));
	}
	sort(vec.begin(), vec.end());
	ll ed = vec[0].e;
	for (ll i = 1; i < vec.size(); i++) {
		if (ed >= vec[i].e) {
			chk[vec[i].idx] = 1;
		}
		else {
			ed = vec[i].e;
		}
	}
	for (ll i = 1; i <= m; i++) {
		if (!chk[i])printf("%lld ", i);
	}
	printf("\n");
	return 0;
}