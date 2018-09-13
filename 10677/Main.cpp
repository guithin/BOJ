#include<stdio.h>

typedef long long ll;

ll sqr(ll x, ll y) {
	ll R = 1;
	while (y--) {
		R *= x;
	}
	return R;
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll ans1 = 10;
		ll ans2 = 10;
		while (1) {
			ll sum1 = 0;
			ll sum2 = 0;
			ll ta = a;
			ll cnt = 0;
			while (ta) {
				sum1 += (ta % 10)*sqr(ans1, cnt);
				ta /= 10;
				cnt++;
			}
			ll tb = b;
			cnt = 0;
			while (tb) {
				sum2 += (tb % 10)*sqr(ans2, cnt);
				tb /= 10;
				cnt++;
			}
			if (sum1 == sum2)break;
			if (sum1 > sum2)ans2++;
			else ans1++;
		}
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}