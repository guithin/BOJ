#include<stdio.h>
#include<math.h>
#include<limits.h>

int main() {
	int n;
	int a[20010] = { 0 };
	long long sum = 0;
	int k = 0;
	long long min =LONG_MAX;
	long long smin = LONG_MAX;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (smin > a[i])
			smin = a[i];
	}
	for (int i = smin; i < 10001; i++) {
		sum = 0;
		for (int j = 0; j < 20005; j++) {
			if (a[j] == 0)
				break;
			sum += abs(i - a[j]);
		}
		if (sum < min) {
			k = i;
			min = sum;
		}
		else
			break;
	}
	printf("%d\n", k);
	return 0;
}