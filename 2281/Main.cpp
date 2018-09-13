#include<bits/stdc++.h>
using namespace std;

int n, m;
int inp[1010];
int nu[1010];
int dp[1010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
		nu[i] = inp[i] + nu[i - 1];
	}
	memset(dp, 40, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 0; j--) {
			if (nu[i] - nu[j] + i - j - 1 > m)break;
			int temp = dp[j] + (m - (nu[i] - nu[j] + i - j - 1))*(m - (nu[i] - nu[j] + i - j - 1));
			if (dp[i] > temp) {
				dp[i] = temp;
			}
		}
	}
	int mini = 1234567890;
	for (int i = n; i + 1; i--) {
		if (nu[n] - nu[i] + n - i - 1 > m)break;
		mini = min(mini, dp[i]);
	}
	printf("%d\n", mini);
	return 0;
}