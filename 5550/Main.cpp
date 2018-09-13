#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

int n, m;
vector<int>vec[11];
int sell[11][2010];
int dp[11][2010];

bool cmp(int &a, int &b) {
	return a > b;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= 10; i++) {
		sort(vec[i].begin(), vec[i].end(), cmp);
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			sell[i][j + 1] = sell[i][j] + vec[i][j] + 2 * j;
		}
	}
	memcpy(dp, sell, sizeof(dp));
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = max(dp[i][j], sell[i][j - k] + dp[i - 1][k]);
			}
		}
	}
	printf("%d\n", dp[10][m]);
	return 0;
}