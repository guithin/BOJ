#include<stdio.h>
#include<vector>

int map[1010][1010] = { 0 };
int num[1010] = { 0 };
std::vector<int>vec[10010];
int idx = 1;
int table[10010] = { 0 };

void dfs(int cur) {
	for (int i = 0; i < vec[cur].size(); i++) {
		if (table[vec[cur][i]] != 0) {
			int temp = table[vec[cur][i]];
			table[vec[cur][i]] = 0;
			dfs(temp);
			continue;
		}
		printf("%d ", vec[cur][i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int start = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			num[i] += map[i][j];
		}
		if (num[i] & 1) {
			printf("-1\n");
			return 0;
		}
		if (!start&&num[i])start = i;
	}
	while (1) {
		bool f = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] >= 1) {
					start = i;
					f = true;
					break;
				}
				if (f)break;
			}
			if (f)break;
		}
		if (!f)break;
		table[start] = idx;
		while (1) {
			vec[idx].push_back(start);
			bool ff = false;
			for (int i = 1; i <= n; i++) {
				if (map[start][i] > 0) {
					map[start][i]--;
					map[i][start]--;
					start = i;
					ff = true;
					break;
				}
			}
			if (!ff)break;
		}
		idx++;
	}
	table[1] = 0;
	dfs(1);
	printf("\n");
	return 0;
}