#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n, m;
int inp[110];
int dp[110][110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
	}
	memset(dp, 200, sizeof(dp));
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	dp[1][1] = inp[1];
	for (int i = 2; i <= n; i++) {
		dp[1][i] = max(dp[1][i - 1], 0) + inp[i];
		for (int j = 2; j <= m; j++) {
			if (i < 2 * j - 1)break;
			dp[j][i] = max(dp[j - 1][i - 2], dp[j][i - 1]);
			for (int k = 2; k < i; k++) {
				dp[j][i] = max(dp[j][i], dp[j - 1][i - k]);
			}
			dp[j][i] += inp[i];
		}
	}
	int maxi = -100000000;
	for (int i = 1; i <= n; i++) {
		if (maxi < dp[m][i])maxi = dp[m][i];
	}
	printf("%d\n", maxi);
	return 0;
}