#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

int n;
int inp[5010];
int dp[5010][5010];

int func(int l, int r) {
	if (dp[l][r] != -1)return dp[l][r];
	if (l >= r)return 0;

	if (inp[l] == inp[r])
		dp[l][r] = max(dp[l][r], func(l + 1, r - 1)) + 2;
	else
		dp[l][r] = max({ dp[l][r], func(l + 1, r - 1), func(l + 1, r), func(l, r - 1) });

	return dp[l][r];
}

int main() {
	scanf("%d", &n);
	memset(dp, 0xff, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (inp[i] == inp[i + 1])
			dp[i][i + 1] = 2;
	}
	printf("%d\n", n - func(1, n));
	return 0;
}