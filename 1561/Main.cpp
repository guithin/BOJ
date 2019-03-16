#include<stdio.h>
#include<limits.h>
typedef long long ll;

ll n, m;
ll inp[10010];

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= m; i++) {
		scanf("%lld", inp + i);
	}
	if (n <= m) {
		printf("%lld\n", n);
		return 0;
	}
	ll l = 1;
	ll r = LLONG_MAX / 10001;
	while (l <= r) {//lower bound
		ll mid = (l + r) / 2;
		ll k = 0;
		for (ll i = 1; i <= m; i++) {
			k += mid / inp[i] + 1;
		}
		if (k >= n)
			r = mid - 1;
		else
			l = mid + 1;
	}
	ll temp = 0;
	for (ll i = 1; i <= m; i++) {
		temp += (l - 1) / inp[i] + 1;
	}
	n -= temp;
	ll ans = 0;
	for (ll i = 1; i <= m; i++) {
		if (!n)break;
		if (l%inp[i] == 0) {
			ans = i;
			n--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}