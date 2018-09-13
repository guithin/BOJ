#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, m, s, t;
vector<int>vec[10010];
vector<int>scv[10010];
vector<vector<int>>scc;
stack<int>stk;
queue<int>q;
int vst[10010];
int low[10010];
int chk[10010];
int sci[10010];
int mem[10010];
int cnt = 1;

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
			chk[top] = 0;
			sc.push_back(top);
			sci[top] = scc.size();
			if (low[top] == vst[top])break;
		}
		scc.push_back(sc);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!vst[i])dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (sci[vec[i][j]] != sci[i])
				scv[sci[i]].push_back(sci[vec[i][j]]);
		}
	}

	for (int i = 0; i < scc.size(); i++) {
		sort(scv[i].begin(), scv[i].end());
		scv[i].resize(unique(scv[i].begin(), scv[i].end()) - scv[i].begin());
//		mem[i] = scc[i].size();
	}

	q.push(sci[s]);
	mem[sci[s]] = scc[sci[s]].size();
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < scv[now].size(); i++) {
			if (mem[scv[now][i]] < mem[now] + scc[scv[now][i]].size()) {
				mem[scv[now][i]] = mem[now] + scc[scv[now][i]].size();
				q.push(scv[now][i]);
			}
		}
	}

	cout << mem[sci[t]] << '\n';
	return 0;
}