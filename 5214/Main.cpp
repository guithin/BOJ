#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int>vec[1010];
vector<int>temp[100010];
vector<int>f;
vector<int>s;
int dist[1010];
queue<int>q;

int main() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			int a; scanf("%d", &a);
			temp[a].push_back(i);
			if (a == n)f.push_back(i);
			if (a == 1)s.push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < temp[i].size(); j++) {
			for (int ii = 0; ii < j; ii++) {
				vec[temp[i][j]].push_back(temp[i][ii]);
				vec[temp[i][ii]].push_back(temp[i][j]);
			}
		}
	}
	memset(dist, 40, sizeof(dist));
	for (auto i : s) {
		dist[i] = 1;
		q.push(i);
	}
	while (q.size()) {
		int now = q.front(); q.pop();
		for (auto i : vec[now]) {
			if (dist[i] > dist[now] + 1) {
				dist[i] = dist[now] + 1;
				q.push(i);
			}
		}
	}
	int mini = 987654321;
	for (int i = 0; i < f.size(); i++) {
		mini = min(mini, dist[f[i]]);
	}
	if (n == 1)mini = 0;
	printf("%d\n", mini >= dist[0] ? -1 : mini + 1);
	return 0;
}