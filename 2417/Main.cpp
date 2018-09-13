#include<stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	long long l = 1;
	long long r = n;
	while (l <= r) {
		long long m = (l + r) / 2;
//		printf("%lld %lld %lld\n", l, r, m);
		if (m >= n/m)
			r = m - 1;
		else if(m<n/m)
			l = m +1;

		if (m == n / m) {
			if (n%m == 0) {
				printf("%lld\n", m);
				return 0;
			}
			else l = m+1;
		}
	}
	printf("%lld\n", l);

	return 0;
}