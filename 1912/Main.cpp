#include<stdio.h>

int main() {
	int n;
	int cnt=0;
	int a[100000] = { 0 };
	long long sum = 0;
	long long max=-10000;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= 0)
			cnt++;
	}
	if (cnt != n) {
		for (int i = 1; i <= n; i++) {
			if (sum > sum + a[i]) {
				if (max < sum)
					max = sum;
			}
			else {
				if (max < sum + a[i])
					max = sum + a[i];
			}

			if (sum + a[i] < 0) {
				sum = 0;
			}
			else
				sum += a[i];
		}
	}
	else
		for (int i = 1; i <= n; i++) {
			if (max < a[i])
				max = a[i];
		}
	printf("%lld\n", max);
	return 0;
}