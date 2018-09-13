#include<stdio.h>
#include<vector>
int inf = 987654321;

struct pos {
	int to;
	int w;
};

std::vector <pos> edge[1010];
int cost[1010] = { 0 };
bool check[1010] = { 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cost[i] = inf;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pos input;
		input.to = b;
		input.w = c;
		edge[a].push_back(input);
	}
	int start, end;
	scanf("%d %d", &start, &end);
	cost[start] = 0;
	for (int i = 1; i <= n; i++) {
		int mini = inf;
		int now = -1;
		for (int j = 1; j <= n; j++) {
			if (check[j] == 0 && cost[j] < mini) {
				mini = cost[j];
				now = j;
			}
		}
		if (now == -1)continue;
		check[now] = true;
		for (int j = 0; j < edge[now].size(); j++) {
			if (cost[edge[now][j].to] > cost[now] + edge[now][j].w) {
				cost[edge[now][j].to] = cost[now] + edge[now][j].w;
			}
		}
	}
	printf("%d\n", cost[end]);
	return 0;
}