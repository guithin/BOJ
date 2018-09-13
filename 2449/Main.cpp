#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

int n, k;
int inp[210];
int dp[210][210][21];

int func(int s, int e, int l) {
	if (dp[s][e][l] != -1)return dp[s][e][l];
	if (s >= e) {
		return dp[s][e][l] = (inp[s] != l);
	}
	int mini = 10000000;
	for (int i = s; i < e; i++) {
		int temp1 = func(s, i, inp[s]) + func(i + 1, e, inp[s]);
		int temp2 = func(s, i, inp[e]) + func(i + 1, e, inp[e]);
		if (inp[s] != l)temp1++;
		if (inp[e] != l)temp2++;
		if (temp1 < mini)mini = temp1;
		if (temp2 < mini)mini = temp2;
	}
	return dp[s][e][l] = mini;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	memset(dp, 0xff, sizeof(dp));
	int mini = 10000000;
	for (int i = 1; i <= k; i++) {
		mini = min(mini, func(1, n, i));
	}
	printf("%d\n", mini);
	return 0;
}