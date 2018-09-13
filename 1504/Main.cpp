#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<algorithm>
using namespace std;
typedef long long ll;

struct pos {
	ll node, cost;
	pos() {};
	pos(ll a, ll b) {
		node = a; cost = b;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

ll n, m;
vector<pos>vec[810];
priority_queue<pos>que;

ll dist[3][810];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dist, 40, sizeof(dist));
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(pos(b, c));
		vec[b].push_back(pos(a, c));
	}
	ll t, q;
	cin >> t >> q;
	dist[0][1] = 0;
	dist[1][t] = 0;
	dist[2][q] = 0;
	que.push(pos(1, 0));
	while (que.size()) {
		pos now = que.top(); que.pop();
		for (ll i = 0; i < vec[now.node].size(); i++) {
			if (dist[0][vec[now.node][i].node] > vec[now.node][i].cost + now.cost) {
				dist[0][vec[now.node][i].node] = vec[now.node][i].cost + now.cost;
				que.push(pos(vec[now.node][i].node, dist[0][vec[now.node][i].node]));
			}
		}
	}
	que.push(pos(t, 0));
	while (que.size()) {
		pos now = que.top(); que.pop();
		for (ll i = 0; i < vec[now.node].size(); i++) {
			if (dist[1][vec[now.node][i].node] > vec[now.node][i].cost + now.cost) {
				dist[1][vec[now.node][i].node] = vec[now.node][i].cost + now.cost;
				que.push(pos(vec[now.node][i].node, dist[1][vec[now.node][i].node]));
			}
		}
	}
	que.push(pos(q, 0));
	while (que.size()) {
		pos now = que.top(); que.pop();
		for (ll i = 0; i < vec[now.node].size(); i++) {
			if (dist[2][vec[now.node][i].node] > vec[now.node][i].cost + now.cost) {
				dist[2][vec[now.node][i].node] = vec[now.node][i].cost + now.cost;
				que.push(pos(vec[now.node][i].node, dist[2][vec[now.node][i].node]));
			}
		}
	}
	//0->1
	//1->t
	//2->q	
	ll ans1 = dist[0][t] + dist[1][q] + dist[2][n];
	ll ans2 = dist[0][q] + dist[2][t] + dist[1][n];
	if (ans1 < dist[0][0] || ans2 < dist[0][0]) {
		printf("%lld\n", ans1 > ans2 ? ans2 : ans1);
	}
	else printf("-1\n");
	return 0;
}