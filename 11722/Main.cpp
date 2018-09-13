#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int inp[1010] = {};
	int dp[1010] = {};
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (inp[i] > inp[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	printf("%d\n", *max_element(dp + 1, dp + 1 + n) + 1);
	return 0;
}