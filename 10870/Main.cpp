#include<stdio.h>

long long fibo[30] = { 0,1,1 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%lld\n", fibo[n]);
	return 0;
}