#include<stdio.h>

long long fibo[1010] = { 1,1,1 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + 2*fibo[i - 2];
	//	printf("%d %lld\n", i, fibo[i]);
		if (fibo[i] > 10007)
			fibo[i] %= 10007;
	}
	printf("%lld\n", fibo[n]);
	return 0;
}