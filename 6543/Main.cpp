#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<memory.h>
using namespace std;

struct start {
	int vst[5010];
	int low[5010];
	int chk[5010];
	int sci[5010];
	int ind[5010];
	stack<int>stk;
	vector<int>vec[5010];
	vector<vector<int>>scc;
	int cnt;
	start() {
		memset(vst, 0, sizeof(vst));
		memset(low, 0, sizeof(low));
		memset(chk, 0, sizeof(chk));
		memset(sci, 0, sizeof(sci));
		memset(ind, 0, sizeof(ind));
		cnt = 0;
	}

	void dfs(int x) {
		vst[x] = low[x] = ++cnt;
		chk[x] = true;
		stk.push(x);
		for (int i = 0; i < vec[x].size(); i++) {
			if (!vst[vec[x][i]]) {
				dfs(vec[x][i]);
				low[x] = min(low[x], low[vec[x][i]]);
			}
			else if (chk[vec[x][i]]) {
				low[x] = min(low[x], low[vec[x][i]]);
			}
		}
		if (vst[x] == low[x]) {
			vector<int>sc;
			while (1) {
				int top = stk.top(); stk.pop();
				chk[top] = false;
				sc.push_back(top);
				sci[top] = scc.size();
				if (vst[top] == low[top])break;
			}
			scc.push_back(sc);
		}
	}

	int main() {
		int v, e;
		scanf("%d", &v);
		if (!v)return 1;
		scanf("%d", &e);
		for (int i = 1; i <= e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		for (int i = 1; i <= v; i++) {
			if (!vst[i])
				dfs(i);
		}
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				if (sci[vec[i][j]] != sci[i])
					ind[sci[i]]++;
			}
		}
		vector<int>ans;
		for (int i = 0; i < scc.size(); i++) {
			if (ind[i])continue;
			for (int j = 0; j < scc[i].size(); j++) {
				ans.push_back(scc[i][j]);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return 0;
	}
};

int main() {
	while (1) {
		start temp;
		if (temp.main()) return 0;
	}
	return 0;
}