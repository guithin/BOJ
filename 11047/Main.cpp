#include<stdio.h>

int main() {
	int n, k;
	int cnt = 0;
	int arr[20] = { 0 };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n; i >= 1; i--) {
		cnt += k / arr[i];
		k %= arr[i];
	}
	printf("%d\n", cnt);
	return 0;
}