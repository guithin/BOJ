#include<stdio.h>
#include<algorithm>

double arr[110] = { 0 };

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp = 0;
			double score = 0;
			scanf("%d %lf", &temp, &score);
			if (arr[temp] < score) {
				arr[temp] = score;
			}
		}
	}
	std::sort(arr + 1, arr + 1 + n);
	double sum = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[n - i];
	}
	printf("%.1lf\n", sum + 1e-9);
	return 0;
}