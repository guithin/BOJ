#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

struct start {
	struct pos {
		int node, flow, cap, rev;
		pos() {};
		pos(int _node, int _flow, int _cap, int _rev) {
			node = _node; flow = _flow; cap = _cap; rev = _rev;
		}
	};

	int n, m;
	vector<pos>vec[10010];
	int chk[10010];
	int nowchk;

	void connect_node(int node_a, int node_b) {
		vec[node_a].push_back(pos(node_b, 0, 1, vec[node_b].size()));
		vec[node_b].push_back(pos(node_a, 0, 0, vec[node_a].size() - 1));
	}

	int dfs(int now, int mini) {
		if (now == 10000)
			return mini;
		chk[now] = nowchk;
		for (int i = 0; i < vec[now].size(); i++) {
			if (vec[now][i].cap == vec[now][i].flow)continue;
			if (chk[vec[now][i].node] == nowchk)continue;
			int temp = dfs(vec[now][i].node, min(mini, vec[now][i].cap - vec[now][i].flow));
			if (temp) {
				vec[now][i].flow += temp;
				vec[vec[now][i].node][vec[now][i].rev].flow -= temp;
				return temp;
			}
		}
		return 0;
	}

	int main() {
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			for (int j = a; j <= b; j++) {
				connect_node(i, 2000 + j);
			}
			connect_node(0, i);
		}
		for (int i = 2001; i <= 2000 + m; i++) {
			connect_node(i, 10000);
		}
		int temp, ans = 0;
		while (temp = dfs(0, 1234567890)) {
			ans += temp;
			nowchk++;
		}
		printf("%d\n", ans);
		return 0;
	}
	start() {
		nowchk = 1;
		memset(chk, 0, sizeof(chk));
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		start temp;
		temp.main();
	}
	return 0;
}