#include<stdio.h>
typedef unsigned long long ll;

int main() {
	ll n;
	scanf("%lld ", &n);
	ll mod = 1234567891ll;
	ll ans = 0ll;
	ll temp = 1ll;
	while (n--) {
		ans += (getchar() - 'a' + 1)*temp;
		ans %= mod;
		temp *= 31; temp %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}