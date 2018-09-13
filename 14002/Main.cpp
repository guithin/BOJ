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
			if (input[i] > input[j] && ans[i] < ans[j] + 1) {
				ans[i] = ans[j] + 1;
				temp[i] = j;
			}
		}
	}
	int maxi = -1;
	int myi = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > maxi) {
			maxi = ans[i];
			myi = i;
		}
	}
	int stack[1010] = { 0 };
	int idx = 0;
	printf("%d\n", maxi);
	int k = myi;
	while (temp[k]!=0) {
		stack[idx] = k;
		k = temp[k];
		idx++;
	}
	stack[idx] = k;
	for (int i = idx; i >= 0; i--) {
		printf("%d ", input[stack[i]]);
	}
	printf("\n");
	return 0;
}