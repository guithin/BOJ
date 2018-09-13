#include<stdio.h>

long long input[1000010] = { 0 };

int main() {
	long long int N, M;
	long long min;
	scanf("%lld %lld", &N, &M);
	for (long long i = 1; i <= N; i++) {
		scanf("%lld", &input[i]);
		if (i == 1)
			min = input[i];
		else if (min > input[i])
			min = input[i];
	}
	long long l = 1;
	long long r = min*M;

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long sum = 0;
		for (long long i = 1; i <= N; i++) {
			sum += mid / input[i];
		}
		if (sum < M) {
			l = mid + 1;
		}
		else if (sum >= M) {
			r = mid - 1;
		}
	}
	printf("%lld\n", l);

	return 0;
}