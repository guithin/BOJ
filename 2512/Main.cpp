#include<stdio.h>
int arr[10010] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (sum < arr[i])
			sum = arr[i];
	}
	int y;
	scanf("%d", &y);
	int l = 1;
	int r = sum;
	int check = 0;
	while (l <= r) {
		check++;
		if (check > 100) {
			printf("Fail\n");
			return 0;
		}
		long long asum = 0;
		int m = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			if (arr[i] < m)
				asum += arr[i];
			else
				asum += m;
		}
//		printf("%d\n", m);
//		printf("%d\n\n", asum);
		if (asum > y)
			r = m - 1;
		else if (asum < y)
			l = m + 1;
		else {
			printf("%d\n", m);
			return 0;
		}
	}
	printf("%d\n", l-1);

	return 0;
}