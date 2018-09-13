#include<stdio.h>
typedef long long ll;

long long a[1000010] = { 0 };
int main() {
	ll n;
	scanf("%lld", &n);
	ll m;
	scanf("%lld", &m);
	long long av = 0;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		av += a[i];
	}
	long long l = 1;
	long long r = av;

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long sum = 0;

		for (ll i = 1; i <= n; i++) {
			if (a[i] - mid>0)
				sum += a[i] - mid;
		}
		if (sum >= m)
			l = mid + 1;
		else if (sum < m)
			r = mid - 1;
	}
	printf("%lld\n", l - 1);
	return 0;
}