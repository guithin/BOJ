#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

struct pos {
	int node, cost;
	pos() {};
	pos(int a, int b) {
		node = a; cost = b;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

int n, m, k;
vector<pos>vec[3010];
priority_queue<pos>q;
int dist[3010];

int main() {
	memset(dist, 40, sizeof(dist));
	//	memset(dist_m, 40, sizeof(dist_m));
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
		vec[b].push_back(pos(a, c));
	}
	for (int i = 1; i <= k; i++) {
		int a;
		scanf("%d", &a);
		dist[a] = 0;
		q.push(pos(a, 0));
	}
	while (q.size()) {
		pos now = q.top(); q.pop();
		for (int i = 0; i < vec[now.node].size(); i++) {
			if (dist[vec[now.node][i].node] > dist[now.node] + vec[now.node][i].cost) {
				dist[vec[now.node][i].node] = dist[now.node] + vec[now.node][i].cost;
				q.push(pos(vec[now.node][i].node, dist[vec[now.node][i].node]));
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			maxi = max({ maxi, dist[i], dist[vec[i][j].node], (dist[i] + dist[vec[i][j].node] + vec[i][j].cost + 1) / 2 });
		}
	}
	printf("%d\n", maxi);
	return 0;
}