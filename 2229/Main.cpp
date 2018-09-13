#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int n;
int inp[1010] = { 0 };
int dp[1010] = { 0 };

int func(int cur) {
	if (dp[cur] != -1)return dp[cur];
	int ed = 0;
	int maxi = inp[cur];
	int mini = inp[cur];
	for (int i = cur, j=1; i >= 1; i--, j++) {
		if (maxi < inp[i])maxi = inp[i];
		if (mini > inp[i])mini = inp[i];
		ed = max(ed, func(cur - j) + maxi - mini);
	}
	return dp[cur] = ed;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", inp + i);
	memset(dp, 0xFF, sizeof(dp));
	printf("%d\n", func(n));
	return 0;
}