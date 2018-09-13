#include<stdio.h>

long long mod = 1000000007;

long long factto(long long a, long long b) {
	long long R = 1;
	for (long long i = a; i <= b; i++) {
		R *= i;
		R %= mod;
	}
	return R;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int t;
//	scanf("%d", &t);
//	while (t--) {
		long long n;
		long long sum = 0;
		scanf("%lld", &n);
		long long ed = 0;
		int temp = n;
		if (n % 2 == 1)
			temp--;
		for (long long r = temp; r >= 0; r -= 2) {
			if (ed == 0) {
				ed = temp;
			}
			else if (ed == n) {
				ed *= r;
			}
			else {
				ed *= r;
				ed %= mod;
				ed *= r + 3;
			}
			ed %= mod;
			sum += ed;
			if (sum > mod)
				sum %= mod;
		}
		if (n % 2 == 0) {
			sum -= (n - 1);
			if (sum < 0) sum += mod;
		}
//		printf("%lld\n", sum);
		sum *= factto(1, n);
		sum %= mod;
		printf("%lld\n", sum);
//	}
	return 0;
}