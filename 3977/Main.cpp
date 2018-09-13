#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<memory.h>
using namespace std;

struct start {
	int n, m;
	vector<int>vec[100010];
	vector<vector<int>>scc;
	stack<int>stk;
	int vst[100010];
	int low[100010];
	int sci[100010];
	int chk[100010];
	int ind[100010];
	int cnt;

	void dfs(int now) {
		vst[now] = low[now] = cnt++;
		chk[now] = 1;
		stk.push(now);
		for (int i = 0; i < vec[now].size(); i++) {
			if (!vst[vec[now][i]]) {
				dfs(vec[now][i]);
				low[now] = min(low[now], low[vec[now][i]]);
			}
			else if (chk[vec[now][i]])
				low[now] = min(low[now], low[vec[now][i]]);
		}
		if (low[now] == vst[now]) {
			vector<int>sc;
			while (1) {
				int top = stk.top(); stk.pop();
				sc.push_back(top);
				chk[top] = 0; sci[top] = scc.size();
				if (low[top] == vst[top])break;
			}
			scc.push_back(sc);
		}
	}

	int main() {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a++;
			b++;
			vec[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!vst[i])dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				if (sci[i] == sci[vec[i][j]])continue;
				ind[sci[vec[i][j]]]++;
			}
		}
		bool flag = false;
		int myi = 0;
		for (int i = 0; i < scc.size(); i++) {
			if (!ind[i]) {
				if (flag) {
					printf("Confused\n");
					return 0;
				}
				flag = true;
				myi = i;
			}
		}
		sort(scc[myi].begin(), scc[myi].end());
		for (int i = 0; i < scc[myi].size(); i++) {
			printf("%d\n", scc[myi][i] - 1);
		}
		return 0;
	}
	start() {
		memset(vst, 0, sizeof(vst));
		memset(low, 0, sizeof(low));
		memset(sci, 0, sizeof(sci));
		memset(chk, 0, sizeof(chk));
		memset(ind, 0, sizeof(ind));
		cnt = 1;
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		start temp;
		temp.main();
		printf("\n");
	}
	return 0;
}