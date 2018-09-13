#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int inp[100010] = { 0 };
int dp[2][100010] = { 0 };

int main() {
	scanf("%d", &n);
	bool flag = false;
	int qwer = -100000;
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
		if (inp[i] > 0)flag = true;
		if (inp[i] > qwer)qwer = inp[i];
	}
	if (!flag) {
		printf("%d\n", qwer);
		return 0;
	}
	int maxi = -100000;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = max(dp[0][i - 1] + inp[i], 0);
		dp[1][i] = max(dp[1][i - 1] + inp[i], 0);
		dp[1][i] = max(dp[1][i], dp[0][i - 1]);
		if (maxi < dp[0][i])maxi = dp[0][i];
		if (maxi < dp[1][i])maxi = dp[1][i];
	}
	printf("%d\n", maxi);
	return 0;
}