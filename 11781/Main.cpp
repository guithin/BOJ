#include<stdio.h>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
typedef long long ll;

struct pos {
	ll node, cost;
	bool is;
	pos() {};
	pos(ll a, ll b, bool c) {
		node = a;
		cost = b;
		is = c;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

ll n, m, s, e;
vector<pos>vec[5010];
priority_queue<pos>q;
ll dist[5010];

ll di(ll a, ll b, ll c, ll d) {
	if (a + b <= c || d <= a) {
		return a + b;
	}
	if (a < c) {
		if (c - a + (d - c) / 2 < b) {	//a c-d b
			return a + b + (d - c) / 2;
		}
		else {							//a c b d
			return 2 * (a + b) - c;
		}
	}
	else {
		if (a + 2 * b < d) {			//c a b d
			return a + 2 * b;
		}
		else {							//c a d b
			return a + b + (d - a) / 2;
		}
	}
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &m, &s, &e);
	s <<= 1;
	e <<= 1;
	memset(dist, 40, sizeof(dist));
	for (ll i = 1; i <= m; i++) {
		ll a, b, c, d, e;
		scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
		vec[a].push_back(pos(b, c << 1, d));
		vec[b].push_back(pos(a, c << 1, e));
	}
	dist[1] = 0;
	q.push(pos(1, 0, false));
	while (q.size()) {
		pos now = q.top(); q.pop();
		for (ll i = 0; i < vec[now.node].size(); i++) {
			ll C;
			if (vec[now.node][i].is)C = di(dist[now.node], vec[now.node][i].cost, s, e);
			else C = dist[now.node] + vec[now.node][i].cost;
			if (dist[vec[now.node][i].node] > C) {
				dist[vec[now.node][i].node] = C;
				q.push(pos(vec[now.node][i].node, dist[vec[now.node][i].node], false));
			}
		}
	}
	ll maxi = -1;
	for (ll i = 1; i <= n; i++) {
		if (maxi < dist[i])maxi = dist[i];
	}
	if (maxi & 1) {
		printf("%lld.5\n", maxi >> 1);
	}
	else {
		printf("%lld\n", maxi >> 1);
	}
	
	return 0;
}