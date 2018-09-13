#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct pos {
	int node, flow, cap, rev;
	pos() {};
	pos(int a, int b, int c, int d) {
		node = a; flow = b; cap = c; rev = d;
	}
};

int n;
char src = 'A', sink = 'Z';
vector<pos>vec[200];
int chk[200];
int nowchk = 1;

int trace[200][2];

int bfs(int now, int mini) {
	queue<int>q, qm;
	qm.push(mini);
	q.push(now);
	chk[now] = nowchk;
	trace[now][0] = -1;
	trace[now][1] = -1;
	int tmp = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		int miin = qm.front(); qm.pop();
		if (u == sink) {
			tmp = miin;
			break;
		}
		for (int i = 0; i < vec[u].size(); i++) {
			pos &v = vec[u][i];
			if (chk[v.node] == nowchk)continue;
			if (v.cap == v.flow)continue;

			trace[v.node][0] = u;
			trace[v.node][1] = i;

			chk[v.node] = nowchk;
			q.push(v.node);
			qm.push(min(miin, v.cap - v.flow));
		}
	}
	if (!tmp)return 0;

	int cur = sink;
	while (1) {
		if (trace[cur][0] == -1)break;
		int k = trace[cur][1];
		cur = trace[cur][0];
		vec[cur][k].flow += tmp;
		vec[vec[cur][k].node][vec[cur][k].rev].flow -= tmp;
	}


	return tmp;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char a, b;
		int c;
		scanf(" %c %c %d", &a, &b, &c);
		vec[a].push_back(pos(b, 0, c, vec[b].size()));
		vec[b].push_back(pos(a, 0, c, vec[a].size() - 1));
	}
	int temp, ans = 0;
	while (temp = bfs(src, 1234567890)) {
		ans += temp;
		nowchk++;
	}
	printf("%d\n", ans);
	return 0;
}