#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<stack>
using namespace std;

int n;

int map[310][310];
int sci[310];
int low[310], vst[310], chk[310];
int cnt = 1;
int asdf[310][310];
int qqq[310][310];
vector<vector<int>>scc;
vector<int>x;
vector<int>y;
stack<int>stk;

void dfs(int now) {
	vst[now] = low[now] = cnt++;
	chk[now] = 1;
	stk.push(now);
	for (int i = 1; i <= n; i++) {
		if (map[now][i]) {
			if (!vst[i]) {
				dfs(i);
				low[now] = min(low[now], low[i]);
			}
			else if (chk[i])
				low[now] = min(low[now], low[i]);
		}
	}
	if (low[now] == vst[now]) {
		vector<int>sc;
		while (1) {
			int top = stk.top(); stk.pop();
			sci[top] = scc.size();
			chk[top] = 0;
			sc.push_back(top);
			if (low[top] == vst[top])break;
		}
		scc.push_back(sc);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scc.clear();
		x.clear();
		y.clear();
		memset(qqq, 0, sizeof(qqq)); memset(map, 0, sizeof(map));
		memset(sci, 0, sizeof(sci)); memset(asdf, 0, sizeof(asdf));
		memset(low, 0, sizeof(low)); memset(vst, 0, sizeof(vst));
		memset(chk, 0, sizeof(chk)); cnt = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
			if (!vst[i])dfs(i);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j]) {
					asdf[sci[i]][sci[j]] = 1;
					qqq[sci[i]][sci[j]] = 1;
				}
			}
		}

		for (int i = 0; i < scc.size(); i++) {
			asdf[i][i] = 1;
			qqq[i][i] = 1;
		}

		for (int k = 0; k < scc.size(); k++) {
			for (int i = 0; i < scc.size(); i++) {
				if (i == k)continue;
				for (int j = 0; j < scc.size(); j++) {
					if (j == k || j == i)continue;
					if (asdf[i][j] && asdf[i][k] && asdf[k][j])
						qqq[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < scc.size(); i++) {
			for (int j = 0; j < scc.size(); j++) {
				if (i == j)continue;
				if (qqq[i][j]) {
					x.push_back(scc[i][0]);
					y.push_back(scc[j][0]);
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < scc.size(); i++)
			if (scc[i].size() == 1)sum++;
		printf("%d\n", x.size() + n - sum);
		for (int i = 0; i < x.size(); i++) {
			printf("%d %d\n", x[i], y[i]);
		}
		for (int i = 0; i < scc.size(); i++) {
			if (scc[i].size() == 1)continue;
			for (int j = 1; j <= scc[i].size(); j++) {
				printf("%d %d\n", scc[i][j - 1], scc[i][j%scc[i].size()]);
			}
		}
	}
	return 0;
}