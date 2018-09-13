#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

struct pos {
	int node, cost;
	pos() {};
	pos(int a, int b) {
		node = a;
		cost = b;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

int v, e;
std::vector<int>vec[500010];
std::vector<int>grp[500010];
std::vector<int>pin;
std::vector<std::vector<int>>scc;
std::stack<int>stk;
std::queue<int>q;
int low[500010] = { 0 };
int dep[500010] = { 0 };
bool chk[500010] = { 0 };
int sci[500010] = { 0 };
int inp[500010] = { 0 };
int cst[500010] = { 0 };
int dst[500010] = { 0 };
int cnt = 0;
int s, p;

void dfs(int x) {
	low[x] = dep[x] = ++cnt;
	chk[x] = true;
	stk.push(x);
	for (int i = 0; i < vec[x].size(); i++) {
		if (!dep[vec[x][i]]) {
			dfs(vec[x][i]);
			low[x] = std::min(low[x], low[vec[x][i]]);
		}
		else if (chk[vec[x][i]]) {
			low[x] = std::min(low[x], low[vec[x][i]]);
		}
	}
	if (dep[x] == low[x]) {
		std::vector<int>temp;
		while (1) {
			int top = stk.top(); stk.pop();
			temp.push_back(top);
			sci[top] = scc.size() + 1;
			chk[top] = false;
			if (low[top] == dep[top])break;
		}
		scc.push_back(temp);
	}
}

void dfs2(int x) {
	if (chk[x])return;
	chk[x] = true;
	for (int i = 0; i < vec[x].size(); i++) {
		if (sci[x] != sci[vec[x][i]]) {
			grp[sci[x]].push_back(sci[vec[x][i]]);
		}
		dfs2(vec[x][i]);
	}
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		scanf("%d", inp + i);
	}
	scanf("%d %d", &s, &p);
	for (int i = 1; i <= p; i++) {
		int a;
		scanf("%d", &a);
		pin.push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!dep[i])dfs(i);
	}
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			cst[i + 1] += inp[scc[i][j]];
		}
	}
	for (int i = 1; i <= v; i++) {
		if (!chk[i]) {
			dfs2(i);
		}
	}
	dst[sci[s]] = cst[sci[s]];
	q.push(sci[s]);
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < grp[now].size(); i++) {
			if (dst[grp[now][i]] < cst[grp[now][i]] + dst[now]) {
				dst[grp[now][i]] = cst[grp[now][i]] + dst[now];
				q.push(grp[now][i]);
			}
		}
	}
	int maxi = -1;
	for (int i = 0; i < p; i++) {
		if (maxi < dst[sci[pin[i]]])
			maxi = dst[sci[pin[i]]];
	}
	printf("%d\n", maxi);
	return 0;
}