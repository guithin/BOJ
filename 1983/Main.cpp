#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

int n;
vector<int>dir1;
vector<int>dir2;

int dp[410][410][410];

int func(int cur, int a, int b) {
	if (cur >= n)return 0;
	if (dp[cur][a][b])return dp[cur][a][b];
	int maxi = -1;
	for (int i = 1; i <= cur - a + 1; i++) {
		for (int j = 1; j <= cur - b + 1; j++) {

		}
	}
}

int main() {
	memset(dp, 200, sizeof(dp));
//	memset(dp[1], 200, sizeof(dp) - sizeof(dp[0]));
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int temp; cin >> temp;
		if (temp)dir1.push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		int temp; cin >> temp;
		if (temp)dir2.push_back(temp);
	}
	for (int i = 0; i <= n; i++)
		dp[i][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= i; k++) {
				if (i + dir1.size() - j >= 0 && i + dir2.size() - k >= 0)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if (i + dir1.size() - j >= 0 && dir2.size() >= k)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
				if (i + dir2.size() - k >= 0 && dir1.size() >= j)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
				if (dir1.size() >= j && dir2.size() >= k && j && k)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + dir1[j - 1] * dir2[k - 1]);
			}
		}
	}

	printf("%d\n", dp[n][dir1.size()][dir2.size()]);
	return 0;
}