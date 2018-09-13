#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

int n;
int inp[10010];
vector<int>vec[10010];
vector<int>grp[10010];
int dp[10010];
bool use[10010];
vector<int>ans;

void maketree(int ed, int x) {
	for (int i = 0; i < vec[x].size(); i++) {
		if (vec[x][i] == ed)continue;
		maketree(x, vec[x][i]);
		grp[x].push_back(vec[x][i]);
	}
}

int func(int x) {
	if (dp[x] != -1)return dp[x];
	if (!grp[x].size()) {
		use[x] = 1;
		return dp[x] = inp[x];
	}
	int temp1 = 0, temp2 = 0;
	int maxi = 0;
	for (int i = 0; i < grp[x].size(); i++) {
		temp1 += func(grp[x][i]);
	}

	for (int i = 0; i < grp[x].size(); i++) {
		for (int j = 0; j < grp[grp[x][i]].size(); j++) {
			temp2 += func(grp[grp[x][i]][j]);
		}
	}

	if (temp1 < temp2 + inp[x]) {
		use[x] = 1;
	}

	return dp[x] = max(temp1, temp2 + inp[x]);
}

void dfs(int x) {
	if (use[x]) {
		ans.push_back(x);
		for (int i = 0; i < grp[x].size(); i++) {
			for (int j = 0; j < grp[grp[x][i]].size(); j++)
				dfs(grp[grp[x][i]][j]);
		}
	}
	else {
		for (int i = 0; i < grp[x].size(); i++) {
			dfs(grp[x][i]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	memset(dp, 0xff, sizeof(dp));
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (vec[i].size() == 1) {
			maketree(0, i);
			printf("%d\n", func(i));
			dfs(i);
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}