#include<stdio.h>
#include<queue>
#include<vector>

int n, m;
int tar[32010] = { 0 };
std::priority_queue<int>q[32010];
std::vector<int>vec[32010];
std::priority_queue<int>q2;
bool chk[32010] = { 0 };

void dfs(int cur) {
	if (tar[cur])return;
	printf("%d ", cur);
	chk[cur] = true;
	while (!q[cur].empty()) {
		int temp = -q[cur].top();
		tar[temp]--;
		q[cur].pop();
		dfs(temp);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
//		if (a <= b)continue;
		tar[b]++;
		q[a].push(-b);
		vec[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!tar[i])q2.push(-i);
/*		if (!tar[i]&&!chk[i]) {
			dfs(i);
		}*/
	}
//	printf("\n");
	while (!q2.empty()) {
		int temp = -q2.top();
		printf("%d ", temp);
		q2.pop();
		for (int i = 0; i < vec[temp].size(); i++) {
			tar[vec[temp][i]]--;
			if (!tar[vec[temp][i]])q2.push(-vec[temp][i]);
		}
	}
	return 0;
}