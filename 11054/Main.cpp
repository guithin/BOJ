#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int input[1010] = { 0 };
	int ans[1010] = { 0 };
	int temp[1010] = { 0 };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
		ans[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (input[i] > input[j] && ans[i] < ans[j] + 1)
				ans[i] = ans[j] + 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= i; j--) {
			if (input[i] > input[j] && temp[i] < temp[j] + 1)
				temp[i] = temp[i] + 1;
		}
	}
	int maxi = -1;
	for (int i = 1; i <= n; i++) {
		if (temp[i] + ans[i] > maxi)maxi = temp[i] + ans[i];
	}
	printf("%d\n", maxi);
	return 0;
}