#include<stdio.h>

int arr[20] = { 0 };
int ans[20] = { 0 };
int num = 11;

void back(int sum, int n) {
	if (sum == n) {
		ans[n]++;
		return;
	}
	else if (sum > n)
		return;
	for (int i = 1; i <= 3; i++) {
		back(sum + i, n);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		back(0, n);
		printf("%d\n", ans[n]);
	}
	return 0;
}