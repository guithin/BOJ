#include<stdio.h>

int input[1010] = { 0 };
int dp[1010] = { 0 };

int dynamic(int k) {
	if (dp[k] > 0)return dp[k];
	if (k == 0)return 0;
	int temp = -1;
	for (int i = 1; i <= k/2; i++) {
		if (dynamic(i)+dynamic(k-i) > temp)
			temp = dynamic(i)+dynamic(k-i);
	}
	if (temp < input[k])temp = input[k];
	dp[k] = temp;
	return dp[k];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	dp[1] = input[1];
	printf("%d\n", dynamic(n));
	return 0;
}