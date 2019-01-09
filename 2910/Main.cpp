#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

map<int, int>bindo;
map<int, int>priority;

struct pos {
	ll nu, bi;
	pos() {};
	pos(ll a, ll b) {
		nu = a; bi = b;
	}
};

int main() {
	ll n, c;
	scanf("%lld %lld", &n, &c);
	ll p = 0;
	for (ll i = 1; i <= n; i++) {
		ll a; scanf("%lld", &a);
		if (bindo.find(a) == bindo.end()) {
			priority[a] = p++;
		}
		bindo[a]++;
	}
	vector<pos>vec;
	for (auto i : bindo) {
		vec.push_back(pos(i.first, i.second));
	}
	sort(vec.begin(), vec.end(), [](pos &a, pos &b) {
		if (a.bi == b.bi)return priority[a.nu] < priority[b.nu];
		return a.bi > b.bi;
	});
	for (auto i : vec) {
		while (i.bi--)printf("%lld ", i.nu);
	}
	printf("\n");
	return 0;
}