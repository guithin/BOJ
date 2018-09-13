#include<stdio.h>

long long dp[100] = { 1,1,1 };

int main() {
	long long n;
	scanf("%lld", &n);
	for (long long i = 3; i <= n; i++) {
		for (long long j = 0; j < i - 1; j++) {
			dp[i] += dp[j];
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}