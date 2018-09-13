#include<stdio.h>

int main() {
	int n, k;
	int input[110] = { 0 };
	int ans[10010] = { 0 };
	int arr[10010] = { 0 };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k / input[i]; j++) {
			arr[input[i] * j]++;
			for (int l = 1; l <= k - input[i] * j; l++) {
				arr[input[i] * j + l] += ans[l];
			}
		}
		for (int j = 0; j <= k; j++) {
			ans[j] += arr[j];
			arr[j] = 0;
		}
	}
	printf("%d\n", ans[k]);
	return 0;
}