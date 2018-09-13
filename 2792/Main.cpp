#include<stdio.h>
#include<limits.h>

int input[300010] = { 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", input + i);
	int l = 0;
	int r = INT_MAX;
	while (l <= r) {
		int mid = (l + r) / 2;
		int num = 0;
		for (int i = 1; i <= m; i++) {
			num += input[i] / mid;
			if (input[i] % mid)num++;
		}
		if (num <= n)r = mid - 1;
		else if (num > n)l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}