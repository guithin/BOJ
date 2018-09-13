#include<stdio.h>
typedef long long ll;

int main() {
	ll n, k, q;
	scanf("%lld %lld %lld", &n, &k, &q);

	if (k == 1) {
		while (q--) {
			ll a, b;
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", a > b ? a - b : b - a);
		}
		return 0;
	}

	while (q--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll cnt = 0;
		while (a != b) {
			if (a > b) {
				a = (a + (k - 2)) / k;
			}
			else {
				b = (b + (k - 2)) / k;
			}
			cnt++;
		}
		printf("%lld\n", cnt);
	}

	return 0;
}