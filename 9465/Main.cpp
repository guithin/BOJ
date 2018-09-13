#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

int inp1[100010] = { 0 };
int inp2[100010] = { 0 };
int dp[100010][2] = { 0 };

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(inp1, 0, sizeof(inp1));
		memset(inp2, 0, sizeof(inp2));
		memset(dp, 0, sizeof(dp));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)scanf("%d", inp1 + i);
		for (int i = 1; i <= n; i++)scanf("%d", inp2 + i);
		dp[1][0] = inp1[1];
		dp[1][1] = inp2[1];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][1] + inp1[i], dp[i - 2][1] + inp1[i]);
			dp[i][1] = max(dp[i - 1][0] + inp2[i], dp[i - 2][0] + inp2[i]);
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
	return 0;
}