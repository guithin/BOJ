#include<stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m=0;
		int a[10000] = { 0 };
		int sum = 0;
		double av = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		av = sum / n;
		for (int i = 0; i < n; i++) {
			if ((double)a[i] > av)
				m++;
		}
		printf("%.3lf%%\n", ((double)m / (double)n + 10e-9)*100);
	}
	return 0;
}