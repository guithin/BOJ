#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n;
char str[200010];
ll p[200010] = { 1 };
const ll key = 29;

int main() {
	scanf("%lld %s", &n, str);
	for (int i = 0; str[i]; i++)str[i] -= 'a' - 1;
	for (ll i = 1; i <= n; i++) {
		p[i] = p[i - 1] * key;
	}
	ll l = 0, r = n;
	while (l <= r) {
		ll mid = (l + r) / 2;
		vector<ll>vec;
		bool flag = false;
		ll c = 0;
		for (ll i = 0; i < mid; i++) {
			c *= key; c += str[i];
		}
		vec.push_back(c);
		for (ll i = mid; i < n; i++) {
			c -= p[mid - 1] * str[i - mid];
			c *= key; c += str[i];
			vec.push_back(c);
		}
		sort(vec.begin(), vec.end());
		for (int i = 1; i < vec.size(); i++) {
			if (vec[i] == vec[i - 1]) {
				flag = true; break;
			}
		}
		if (flag || !mid) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", r);
	return 0;
}