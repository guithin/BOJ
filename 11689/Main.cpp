#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
typedef long long ll;

vector<ll>vec;
ll ans;
ll n;
ll exc = 0xfffffffffffff800;

void back(ll cur, ll bit, ll op) {
	if (cur >= (ll)vec.size()) {
		if (!bit)return;
		ll temp = 1;
		ll idx = 1;
		while (bit) {
			if (bit & 1) {
				temp *= vec[vec.size() - idx];
			}
			bit >>= 1;
			idx++;
		}
		if (op) ans += n / temp;
		else ans -= n / temp;
		return;
	}
	back(cur + 1, bit << 1, op);
	back(cur + 1, (bit << 1) | 1LL, op ^ 1LL);
}

int main() {
	scanf("%lld", &n);
	ll t = n;
	for (ll i = 2; i*i <= t; i++) {
		if (!(t%i)) {
			vec.push_back(i);
			while (!(t%i))t /= i;
		}
	}
	if (t != 1)
		vec.push_back(t);
	back(0LL, 0LL, 0LL);
	printf("%lld\n", n - ans);
	return 0;
}