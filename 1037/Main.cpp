#include<stdio.h>
#include<algorithm>

long long gcd(long long a, long long b) {
	return !(a%b) ? b : gcd(b, a%b);
}

int main() {
	long long n;
	scanf("%lld", &n);
	long long input[55] = { 0 };
	for (long long i = 1; i <= n; i++)
		scanf("%lld", &input[i]);
	std::sort(input + 1, input + 1 + n);
	long long sum = 1;
	sum *= input[1] * input[n];
	if (sum == 1)sum *= 2;
	printf("%lld\n", sum);

	return 0;
}