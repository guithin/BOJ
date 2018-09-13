#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Edge {
	int to, cost;
	Edge() {}
	Edge(int t, int c) :to(t), cost(c) {}
};

int ind[10001], t[10001];
vector<Edge> adj[10001];
vector<int> past[10001];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0, u, v, c; i < M; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(Edge(v, c));
		ind[v]++;
	}

	int S, E; scanf("%d %d", &S, &E);
	memset(t, 0xff, sizeof(t));
	t[S] = 0;

	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!ind[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int &next = adj[cur][i].to;
			if (0 <= t[cur] && t[next] <= t[cur] + adj[cur][i].cost) {
				if (t[next] < t[cur] + adj[cur][i].cost) {
					past[next].clear();
					t[next] = t[cur] + adj[cur][i].cost;
				}
				past[next].push_back(cur);
			}
			if (--ind[adj[cur][i].to] == 0) q.push(adj[cur][i].to);
		}
	}

	int cnt = 0;
	q.push(E);
	bool chk[10001] = { 0 };
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < past[cur].size(); i++) {
			cnt++;
			if(chk[past[cur][i]]==false)
				q.push(past[cur][i]);
			chk[past[cur][i]] = true;
		}
	}
	printf("%d\n%d\n", t[E], cnt);
	return 0;
}