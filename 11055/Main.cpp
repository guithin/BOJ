#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int input[1010] = { 0 };
	int ans[1010] = { 0 };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
		ans[i] = input[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (input[i] > input[j] && ans[i] < ans[j] + input[i]) {
				ans[i] = ans[j] + input[i];
			}
		}
	}
	int maxi = -1;
	for (int i = 1; i <= n; i++) {
		if (maxi < ans[i])maxi = ans[i];
	}
	printf("%d\n", maxi);
	return 0;
}