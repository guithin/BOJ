#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int dp[1000010] = { 0 };

int func(int cur) {
	if (dp[cur] != dp[1000009])return dp[cur];
	int a = 1000000;
	int b = 1000000;
	int c = 1000000;
	a = func(cur - 1);
	if (!(cur & 1))b = func(cur / 2);
	if (!(cur % 3))c = func(cur / 3);
	return dp[cur] = min(a, min(b, c)) + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, 40, sizeof(dp));
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	printf("%d\n", func(n));
	return 0;
}