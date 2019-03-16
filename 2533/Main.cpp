#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>vec[1000010];
int dp[1000010][2];

int back(int nd, int fr, int flag) {
	if (dp[nd][flag] != -1)return dp[nd][flag];
	int sum = 0;
	dp[nd][0] = dp[nd][1] = 0;
	for (int i : vec[nd]) {
		if (i == fr)continue;
		dp[nd][0] += back(i, nd, 1);
		dp[nd][1] += min(back(i, nd, 1), back(i, nd, 0));
	}
	dp[nd][1]++;
	return dp[nd][flag];
}

int main() {
	memset(dp, 0xff, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int q, w;
		scanf("%d %d", &q, &w);
		vec[q].push_back(w);
		vec[w].push_back(q);
	}
	printf("%d\n", min(back(1, 0, 0), back(1, 0, 1)));

	return 0;
}