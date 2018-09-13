#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>

int v, e;
std::vector<int>vec[10010];
std::vector<std::vector<int>>scc;
std::stack<int>stk;
bool chk[10010] = { 0 };
bool chk2[10010] = { 0 };
int low[10010] = { 0 };
int deep[10010] = { 0 };
int cnt = 1;

void dfs(int now) {
	deep[now] = low[now] = cnt++;
	chk[now] = true;
	chk2[now] = 1;
	stk.push(now);
	for (int i = 0; i < vec[now].size(); i++) {
		if (!deep[vec[now][i]]) {
			dfs(vec[now][i]);
			low[now] = std::min(low[now], low[vec[now][i]]);
		}
		else if(chk[vec[now][i]])
			low[now] = std::min(low[now], low[vec[now][i]]);
	}
	if (deep[now] == low[now]) {
		std::vector<int>temp;
		while (low[stk.top()] != deep[stk.top()]) {
			temp.push_back(stk.top());
			chk[stk.top()] = 0;
			stk.pop();
		}
		temp.push_back(stk.top());
		chk[stk.top()] = 0;
		stk.pop();
		scc.push_back(temp);
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
		if (!chk2[i])dfs(i);
	}
	for (int i = 0; i < scc.size(); i++) {
		std::sort(scc[i].begin(), scc[i].end());
	}
	std::sort(scc.begin(), scc.end());
	printf("%d\n", scc.size());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}