#include<stdio.h>

long long r, c;
long long cnt = 0;
long long sqr(long long x, long long y) {
	long long sum = 1;
	for (long long i = 0; i < y; i++) {
		sum *= x;
	}
	return sum;
}

long long F(long long x1, long long x2, long long y1, long long y2) {
	long long sum = 0;
	if (x2 <= x1+1 &&y2 <= y1+1)
		return 0;


	if (r > (x2 + x1) / 2 && c > (y2 + y1) / 2) {
		sum = (x2 - x1)*(y2 - y1) * 3 / 4;
		return F((x2 + x1) / 2, x2, (y2 + y1) / 2, y2) + sum;
	}


	else if (x2>x1+1&&r > (x2 + x1) / 2) {
		sum = (x2 - x1)*(y2 - y1) / 2;
		y2 = (y1 + y2) / 2;
		return F((x2 + x1) / 2, x2, y1, y2) + sum;
	}


	else if (c > (y2 + y1) / 2) {
		x2 = (x1 + x2) / 2;
		sum = (x2 - x1)*(y2 - y1) / 2;
		return F(x1, x2, (y2 + y1) / 2, y2) + sum;
	}


	else {
		return F(x1, (x2 + x1) / 2, y1, (y2 + y1) / 2);
	}
}

int main() {
	long long n;
	scanf("%lld %lld %lld", &n, &r, &c);
	r++; c++;
	long long N = sqr(2, n);
	printf("%lld\n", F(0, N, 0, N));
	return 0;
}