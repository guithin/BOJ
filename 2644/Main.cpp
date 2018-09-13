#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[110];
bool chk[110];
queue<int> q;

int bfs(int x, int y) {
	int num = 0;
	q.push(x);
	chk[x] = true;
	while (q.size()) {
		int sz = q.size();
		for (int j = 0; j < sz; j++) {
			int v = q.front(); q.pop();
			if (v == y)return num;
			for (int i = 0; i < adj[v].size(); i++) {
				if (!chk[adj[v][i]]) {
					q.push(adj[v][i]);
					chk[adj[v][i]] = true;
				}
			}
			if (q.empty())return -1;
		}
		num++;
	}
}


int main() {
	int n, a, b, m, x, y;
	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << bfs(a, b) << '\n';
}