#include<bits/stdc++.h>
using namespace std;

int n;
int inp[12][12];
int dp[1050][12];

int func(int bit, int last) {
	int &val = dp[bit][last];
	if (val != dp[11][11])return val;
	if (!bit)return val = inp[1][last];
	for (int i = 2; i <= n; i++) {
		if (bit&(1 << (i - 1))) {
			int temp = func(bit ^ (1 << (i - 1)), i);
			if (val > temp + inp[i][last])
				val = temp + inp[i][last];
		}
	}
	return val;
}

int main() {
	scanf("%d", &n);
	memset(dp, 40, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &inp[i][j]);
			if (!inp[i][j])inp[i][j] = dp[11][11];
		}
	}
	int ans = 1234567890;
	for (int i = 2; i <= n; i++) {
		int temp = func(((1 << n) - 2) ^ (1 << (i - 1)), i);
		if (ans > temp + inp[i][1])
			ans = temp + inp[i][1];
	}
	printf("%d\n", ans);
	return 0;
}