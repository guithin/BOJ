#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<stack>

struct pos {
	int n, m;
	std::vector<int>vec[100010];
	std::vector<int>tree[100010];
	std::vector<std::vector<int>>scc;
	std::stack<int>stk;
	int chk[100010]; int idx[100010]; int low[100010]; int ind[100010]; int sccidx[100010];
	int cnt, ans;
	pos() {
		memset(chk, 0, sizeof(chk));
		memset(idx, 0, sizeof(idx));
		memset(low, 0, sizeof(low));
		memset(ind, 0, sizeof(ind));
		memset(sccidx, 0, sizeof(sccidx));
		cnt = 0;
		ans = 0;
	};
	void dfs(int x) {
		low[x] = idx[x] = ++cnt;
		chk[x] = true;
		stk.push(x);
		for (int i = 0; i < vec[x].size(); i++) {
			if (!idx[vec[x][i]]) {
				dfs(vec[x][i]);
				low[x] = std::min(low[x], low[vec[x][i]]);
			}
			else if (chk[vec[x][i]]) {
				low[x] = std::min(low[x], low[vec[x][i]]);
			}
		}
		if (idx[x] == low[x]) {
			std::vector<int>temp;
			while (1) {
				chk[stk.top()] = false;
				sccidx[stk.top()] = scc.size() + 1;
				temp.push_back(stk.top());
				if (idx[stk.top()] == low[stk.top()]) {
					stk.pop();
					break;
				}
				stk.pop();
			}
			scc.push_back(temp);
		}
	}

	int main() {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!idx[i]) {
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				if (sccidx[i] != sccidx[vec[i][j]]) {
					tree[sccidx[i]].push_back(sccidx[vec[i][j]]);
					ind[sccidx[vec[i][j]]]++;
				}
			}
		}
		for (int i = 1; i <= scc.size(); i++) {
			if (!ind[i])ans++;
		}
		printf("%d\n", ans);
		return 0;
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		pos temp;
		temp.main();
	}
	return 0;
}