#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

int vst[100010];
int low[100010];
int sci[100010];
int chk[100010];
int cnt = 0;
vector<vector<int>>scc;
vector<int>vec[100010];
vector<int>rev[100010];
stack<int>stk;
int n, m;

void dfs(int x) {
	vst[x] = low[x] = ++cnt;
	chk[x] = true;
	stk.push(x);
	for (int i = 0; i < vec[x].size(); i++) {
		if (!vst[vec[x][i]]) {
			dfs(vec[x][i]);
			low[x] = min(low[x], low[vec[x][i]]);
		}
		else if (chk[vec[x][i]])
			low[x] = min(low[x], low[vec[x][i]]);
	}
	if (low[x] == vst[x]) {
		vector<int>temp;
		while (1) {
			int top = stk.top();
			stk.pop();
			chk[top] = false;
			temp.push_back(top);
			sci[top] = scc.size();
			if (low[top] == vst[top])break;
		}
		scc.push_back(temp);
	}
}

int oto[100010];
int ogo[100010];
queue<int>q;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		rev[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vst[i])dfs(i);
	}
	q.push(sci[1]);
	oto[sci[1]] = scc[sci[1]].size();
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < scc[now].size(); i++) {
			for (int j = 0; j < vec[scc[now][i]].size(); j++) {
				if (sci[vec[scc[now][i]][j]] == sci[scc[now][i]])continue;
				if (oto[sci[vec[scc[now][i]][j]]] < oto[sci[scc[now][i]]] + scc[sci[vec[scc[now][i]][j]]].size()) {
					oto[sci[vec[scc[now][i]][j]]] = oto[sci[scc[now][i]]] + scc[sci[vec[scc[now][i]][j]]].size();
					q.push(sci[vec[scc[now][i]][j]]);
				}
			}
		}
	}
	q.push(sci[1]);
	ogo[sci[1]] = scc[sci[1]].size();
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < scc[now].size(); i++) {
			for (int j = 0; j < rev[scc[now][i]].size(); j++) {
				if (sci[rev[scc[now][i]][j]] == sci[scc[now][i]])continue;
				if (ogo[sci[rev[scc[now][i]][j]]] < ogo[sci[scc[now][i]]] + scc[sci[rev[scc[now][i]][j]]].size()) {
					ogo[sci[rev[scc[now][i]][j]]] = ogo[sci[scc[now][i]]] + scc[sci[rev[scc[now][i]][j]]].size();
					q.push(sci[rev[scc[now][i]][j]]);
				}
			}
		}
	}
	int maxi = -1;
	for (int i = 0; i < scc.size(); i++) {
		if (ogo[i]) {
			for (int j = 0; j < scc[i].size(); j++) {
				for (int k = 0; k < vec[scc[i][j]].size(); k++) {
					if (oto[sci[vec[scc[i][j]][k]]]) {
						if (oto[sci[vec[scc[i][j]][k]]] + ogo[i] > maxi)
							maxi = oto[sci[vec[scc[i][j]][k]]] + ogo[i];
					}
				}
			}
		}
	}
	printf("%d\n", maxi - scc[sci[1]].size());
	return 0;
}