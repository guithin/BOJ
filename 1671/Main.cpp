#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long ll;

struct pos {
	ll node, flow, cap, rev;
	pos() {};
	pos(ll _node, ll _flow, ll _cap, ll _rev) {
		node = _node; flow = _flow; cap = _cap; rev = _rev;
	}
};

struct inp {
	ll a, b, c, d;
	inp() {
		d = 2;
	}
	inp(ll _a, ll _b, ll _c) {
		a = _a; b = _b; c = _c; d = 2;
	}
	bool operator<(const inp&io)const {
		if (a == io.a&&b == io.b)return c < io.c;
		if (a == io.a)return b < io.b;
		return a < io.a;
	}
	bool operator!=(const inp&io)const {
		return a != io.a || b != io.b || c != io.c;
	}
	bool operator==(const inp&io)const {
		return a == io.a && b == io.b && c == io.c;
	}
};

ll n;
vector<pos>vec[10010];
ll chk[10010];
ll nowchk = 1;
inp ddd[1010];

void connect_node(ll node_a, ll node_b, ll maxflow) {
	vec[node_a].push_back(pos(node_b, 0, maxflow, vec[node_b].size()));
	vec[node_b].push_back(pos(node_a, 0, 0, vec[node_a].size() - 1));
}

ll dfs(ll now, ll mini) {
	if (now == 10000)
		return mini;
	chk[now] = nowchk;
	for (ll i = 0; i < vec[now].size(); i++) {
		if (vec[now][i].cap == vec[now][i].flow)continue;
		if (chk[vec[now][i].node] == nowchk)continue;
		ll temp = dfs(vec[now][i].node, min(mini, vec[now][i].cap - vec[now][i].flow));
		if (temp) {
			vec[now][i].flow += temp;
			vec[vec[now][i].node][vec[now][i].rev].flow -= temp;
			return temp;
		}
	}
	return 0;
}

int main() {

	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &ddd[i].a, &ddd[i].b, &ddd[i].c);
	}
	sort(ddd + 1, ddd + 1 + n);
	vector<inp>use;
	ll temp, ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (i == n) {
			use.push_back(ddd[i]);
			continue;
		}
		if (ddd[i] != ddd[i + 1]) {
			use.push_back(ddd[i]);
		}
		else {
			int tmp = i + 1;
			while (ddd[i] == ddd[tmp]) {
				ddd[i].d += ddd[tmp].d - 1;
				tmp++;
				ans++;
			}
			use.push_back(ddd[i]);
			i = tmp - 1;
		}
	}
	for (ll i = 0; i < use.size(); i++) {
		for (ll j = 0; j < use.size(); j++) {
			if (i == j)continue;
			if (use[i].a >= use[j].a&&use[i].b >= use[j].b&&use[i].c >= use[j].c) {
				connect_node(i + 1, j + 2001, 1);
			}
		}
	}
	for (ll i = 0; i < use.size(); i++) {
		connect_node(0, i + 1, use[i].d);
	}

	for (ll i = 0; i < use.size(); i++) {
		connect_node(2001 + i, 10000, 1);
	}

	while (temp = dfs(0, 1234567890)) {
		ans += temp;
		nowchk++;
	}
	printf("%lld\n", n - ans);
	return 0;
}