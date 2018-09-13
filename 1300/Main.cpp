#include<stdio.h>

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long l = 1;
	long long r = n*n;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long sum = 0;
		long long range = 0;
		for (long long i = 1; i <= n; i++) {
			if (mid <= n*i) {
				sum += mid / i;
			}
			else
				sum += n;
		}
//		printf("%lld %lld\n", mid, sum);
		if (m > sum) {
			l = mid + 1;
		}
		else if (m <= sum) {
			r = mid - 1;
		}
	}
	printf("%lld\n", l);
	return 0;
}