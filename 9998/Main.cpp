#include<stdio.h>
#include<limits.h>
typedef long long ll;

ll absx(ll x) {
	return x > 0 ? x : -x;
}

ll n;
ll y[300010];
ll d[300010];

int main() {
	scanf("%lld", &n);
	ll mid = n / 2 + 1;
	ll maxi = -1;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &y[i]);
		if (maxi < y[i] - absx(i - mid)) {
			maxi = y[i] - absx(i - mid);
		}
	}
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		if (maxi < d[i] - absx(i - mid)) {
			maxi = d[i] - absx(i - mid);
		}
	}
	ll l = 0;
	ll r = maxi;
	if (!maxi) {
		printf("0\n"); return 0;
	}
	ll ans = LLONG_MAX;
	while (l<=r) {
		ll miid = (l + r) / 2;
		ll sum = 0;
		ll sumtemp = 0;
		for (ll i = 1; i <= n; i++) {
			sum += absx(y[i] - absx(mid - i) - miid);
			sumtemp += absx(y[i] - absx(mid - i) - miid - 1);
			sum += absx(d[i] - absx(mid - i) - miid);
			sumtemp += absx(d[i] - absx(mid - i) - miid - 1);
		}
		if (sum > sumtemp) {
			if (ans > sumtemp)ans = sumtemp;
			l = miid + 1;
		}
		else if (sum < sumtemp) {
			if (ans > sum)ans = sum;
			r = miid - 1;
		}
		else {
			if (ans > sum)ans = sum;
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}