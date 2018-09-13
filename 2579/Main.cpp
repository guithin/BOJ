#include<bits/stdc++.h>
using namespace std;

int n;
int inp[310];
int dp[310];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	dp[1] = inp[1];
	dp[2] = inp[1] + inp[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + inp[i];
		dp[i] = max(dp[i], dp[i - 3] + inp[i] + inp[i - 1]);
	}
	printf("%d\n", dp[n]);
	return 0;
}