#include<stdio.h>

int input[100010] = { 0 };

int main() {
	int n, m;
	int min = 0;
	int ssum = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
		if (min < input[i]) {
			min = input[i];
		}
		ssum += input[i];
	}

	int l = min;
	int r = ssum;
//	printf("%d %d\n", l, r);

	while (l <= r) {
		int mid = (l + r) / 2;
//		printf("%d\n", mid);
		int sum = 0;
		int tsum = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (tsum+input[i] <= mid)
				tsum += input[i];
			else {
				cnt++;
				tsum = input[i];
			}
		}
		if (tsum)cnt++;
		if (cnt > m) {
			l = mid + 1;
		}
		else if (cnt <= m) {
			r = mid - 1;
		}
	}
	printf("%d\n", r+1);
	return 0;
}