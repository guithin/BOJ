#include<stdio.h>

int n, m;
int inp[100010];
int dp[100010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
		dp[i] = dp[i - 1] + (inp[i - 1] > inp[i])*(i > 1);
	}
	dp[n + 1] = dp[n];
	while (m--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = dp[l - 1] + (dp[n] - dp[r + 1]);
		if (l != 1 && inp[r] < inp[l - 1])ans++;
		if (r != n && inp[l] > inp[r + 1])ans++;
		ans += (r - l) - (dp[r] - dp[l]) + 1;
		printf("%d\n", ans);
	}
	return 0;
}