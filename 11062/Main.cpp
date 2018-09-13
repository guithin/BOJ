#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int n;
int inp[1010] = {};
int dp[1010][1010] = {};

int func(int x, int y, int len) {
	if (len == n + 1)return 0;
	if (dp[x][y] != -1)return dp[x][y];
	int l = 0, r = 0;
	int temp = len & 1;
	if (x <= n)l = func(x + 1, y, len + 1) + inp[x] * temp;
	if (y <= n)r = func(x, y + 1, len + 1) + inp[n - y + 1] * temp;
	if (len & 1)return dp[x][y] = max(l, r);
	return dp[x][y] = min(l, r);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(inp, 0, sizeof(inp));
		memset(dp, 0xff, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", inp + i);
		}
		printf("%d\n", func(1, 1, 1));
	}
	return 0;
}