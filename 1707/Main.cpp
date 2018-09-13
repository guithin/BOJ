#include<stdio.h>
#include<vector>
#include<memory.h>

std::vector<int>vec[20010];
int V, E;
int table[20010] = { 0 };
bool flag = true;

void dfs(int node, int deep) {
	for (int i = 0; i < vec[node].size(); i++) {
		if (table[vec[node][i]]) {
			if ((deep - table[vec[node][i]]) % 2) {
				flag = false;
				return;
			}
			continue;
		}
		if (!flag)return;
		table[vec[node][i]] = deep;
		dfs(vec[node][i], deep + 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(table, 0, sizeof(table));
		flag = true;
		scanf("%d %d", &V, &E);
		for (int i = 1; i <= V; i++)vec[i].clear();
		for (int i = 1; i <= E; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (table[i] == 0) {
				table[i] = 1;
				dfs(i, 2);
			}
		}
		printf("%s\n", flag ? "YES" : "NO");

	}
	return 0;
}