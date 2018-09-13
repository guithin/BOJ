#include<stdio.h>

long long function(long long x) {
	bool flag = x % 2;
	x /= 2;
	long long sum = 0;
	if (x % 2 == 0)sum = (x / 2)*(x + 1);
	else sum = ((x + 1) / 2)*x;
	sum *= 2;
	if (flag)sum += x + 1;
	return sum;
}

int main() {
	long long t;
	for (scanf("%lld", &t); t; t--) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		y -= x;
		x = 0;
		long long l = 0;
		long long r = 400000;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (function(mid) < y) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		printf("%lld\n", l);
	}
	return 0;
}