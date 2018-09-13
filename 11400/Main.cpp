#include<stdio.h>
#include<memory.h>
#include<stack>
#include<vector>
#include<algorithm>

struct edge {
	int s, e;
	edge() {};
	edge(int a, int b) {
		s = a; e = b;
	}
	bool operator<(const edge &io)const {
		if (s == io.s)return e < io.e;
		return s < io.s;
	}
};

int v, e;
std::vector<int>vec[100010];
std::vector<edge>p;
std::stack<int>stk;

int vst[100010] = { 0 };
int low[100010] = { 0 };
int cnt = 0;
int chk[100010] = { 0 };
int aaaa = 1;
int sci[100010] = { 0 };

/*
int dfs(int x, int ed) {
	if (vst[x])return vst[x];
	vst[x] = ++cnt;
	int mini = 1234567890;
	for (int i = 0; i < vec[x].size(); i++) {
		if (vec[x][i] == ed)continue;
		int temp = dfs(vec[x][i], x);
		if (temp > vst[x]) {
//			printf("%d %d\n", x, vec[x][i]);
			if (x > vec[x][i])p.push_back(edge(vec[x][i], x));
			else p.push_back(edge(x, vec[x][i]));
		}
		if (temp < mini)
			mini = temp;
	}
	vst[x] = 0;
	cnt--;
	return mini;
}
*/

void dfs(int x, int ed) {
//	if (low[x])return;
	vst[x] = low[x] = ++cnt;
	chk[x] = 1;
	stk.push(x);
	for (int i = 0; i < vec[x].size(); i++) {
		if (vec[x][i] == ed)continue;
		if (!vst[vec[x][i]]) {
			dfs(vec[x][i], x);
			low[x] = std::min(low[x], low[vec[x][i]]);
		}
		else if (chk[vec[x][i]])
			low[x] = std::min(low[x], low[vec[x][i]]);
	}
	if (vst[x] == low[x]) {
		while (1) {
			int top = stk.top();
			sci[top] = aaaa;
			stk.pop();
			chk[top] = false;
			if (vst[top] == low[top])break;
		}
		aaaa++;
	}
}

int find(int x) {
	if (low[x] == x)return x;
	return low[x] = find(low[x]);
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (sci[i] < sci[vec[i][j]]) {
				if (i > vec[i][j])
					p.push_back(edge(vec[i][j], i));
				else
					p.push_back(edge(i, vec[i][j]));
			}
		}
	}
	printf("%d\n", p.size());
	std::sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++) {
		printf("%d %d\n", p[i].s, p[i].e);
	}
	return 0;
}