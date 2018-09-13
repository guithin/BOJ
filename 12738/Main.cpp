#include<stdio.h>
#include<memory.h>

int dp[1000010] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, 60, sizeof(dp));
	dp[0] = -1111111111;
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		int l = 0;
		int r = n;
		while (l <= r) {
			int miid = (l + r) / 2;
			if (dp[miid] > temp) {
				r = miid - 1;
			}
			else {
				l = miid + 1;
			}
		}
		if (dp[l - 1] < temp)dp[l] = temp;
	}
	for (int i = n; i >= 1; i--) {
		if (dp[i] != dp[n + 1]) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}