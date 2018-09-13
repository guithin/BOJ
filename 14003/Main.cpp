#include<stdio.h>
#include<memory.h>
#include<limits.h>

int dp[1000010] = { 0 };
int num[1000010] = { 0 };
int ans[1000010] = { 0 };
int stack[1000010] = { 0 };
int idx = 0;

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, 63, sizeof(dp));
	memset(ans, 63, sizeof(ans));
//	printf("%d\n", dp[1]);
	dp[0] = INT_MIN/2;
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		num[i] = temp;
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
		if (dp[l - 1] == temp)l--;
		ans[i] = dp[l - 1];
		dp[l] = temp;
		
	}
	int myi = 0;
	for (int i = n; i >= 1; i--) {
		if (dp[i] != dp[n + 1]) {
			printf("%d\n", i);
			myi = i;
			break;
		}
	}
	int k = 0;
	for (int i = n; i >= 1; i--) {
		if (dp[myi] == num[i]) {
			k = i;
			break;
		}
	}
	bool flag = true;

	while (flag) {
		stack[idx] = num[k];
		idx++;
		for (int i = k - 1; i >= 0; i--) {
			if (ans[k] == num[i]) {
				k = i;
				break;
			}
			else if (ans[k] < -1000000000)flag = false;
		}
	}
	for (int i = idx-1; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
	return 0;
}