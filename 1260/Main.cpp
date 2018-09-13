#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
bool graph[1001][1001];
bool visit[1001];

void dfs(int cur) {
	printf("%d ", cur);
	for (int nxt = 1; nxt <= N; nxt++) {
		if (graph[cur][nxt] && !visit[nxt]) {
			visit[nxt] = true;
			dfs(nxt);
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		int b, e; scanf("%d %d", &b, &e);
		graph[b][e] = graph[e][b] = true;
	}

	fill(visit, visit + N + 1, false);
	visit[V] = true; dfs(V); printf("\n");
	fill(visit, visit + N + 1, false);
	queue<int> q; q.push(V); visit[V] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int nxt = 1; nxt <= N; nxt++) {
			if (graph[cur][nxt] && !visit[nxt]) {
				q.push(nxt);
				visit[nxt] = true;
			}
		}
	}
	printf("\n");

	return 0;
}