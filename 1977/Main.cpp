#include<stdio.h>
#include<math.h>
int main() {
	long long a, b, cnt = 0, gh = 1;
	long long k = 1;
	long long sum = 0;
	scanf("%lld %lld", &a, &b);
	k = sqrt(a);
	if (k*k == a)
		gh = 1;
	else
		gh = (k + 1)*(k + 1);
	while (1) {
		if (k*k > b)
			break;
		if (k*k >= a&&k*k <= b) {
			sum += k*k;
		}
		k++;
	}
	if (sum == 0)
		printf("-1\n");
	else {
		printf("%lld\n%lld\n", sum, gh);
	}
	return 0;
}