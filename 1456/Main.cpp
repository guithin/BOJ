#include<stdio.h>
#include<limits.h>

int a[10000010] = { 1,1,0 };
long long end = 0;

long long sqr(long long x, long long y) {
	long long R = 1;
	for (long long i = 1; i <= y; i++) {
		if (LLONG_MAX / x < R) {
			return end+1;
		}
		R *= x;
		
	}
	return R;
}

int main() {
	long long start = 0;
	long long count = 0;
	long long cnt = 0;
	scanf("%lld %lld", &start, &end);
	for (long long i = 2; i*i <= end; i++) {
		if (a[i]>0)continue;
		a[i] = 2;
		for (long long j = 2; i*j <= 10000000; j++) {
			a[i*j] = 1;
		}
		long long j = 2;
		while (sqr(i, j) <= end) {
			if (sqr(i, j) >= start&&sqr(i, j) <= end) {
				count++;
			}
			j++;
		}
	}
	printf("%lld\n", count);
	return 0;
}