#include<stdio.h>

long long a[10010] = { 0 };
long long sum = 0;

int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	long long av = sum / n;
	long long l = 1;
	long long m;
	int A = 0;
	while (l<=av) {
		A = 0;
		m = (l + av) / 2;
		for (int i = 1; i <= k; i++) {
			A += a[i] / m;
		}
		if (A < n)
			av = m - 1;
		else if (A >= n)
			l = m + 1;
		else
			break;
	}
	printf("%lld\n", l-1);
	return 0;
}