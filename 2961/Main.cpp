#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[11], b[11];
ll ans = 1LL << 60;

void back(ll i, ll q, ll w) {
	if (i == n + 1) {
		if (q == 1 && !w)return;
		ans = min(ans, abs(q - w));
		return;
	}
	back(i + 1, q, w);
	if (abs(q*a[i] - w - b[i]) <= 1000000000LL)
		back(i + 1, q*a[i], w + b[i]);
}

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", a + i, b + i);
	}
	back(1, 1, 0);
	printf("%lld\n", ans);
	return 0;
}