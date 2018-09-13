#include<stdio.h>
#include<algorithm>
#include<queue>

struct pos {
	int idx;
	int val;
	pos() {};
	pos(int a, int b) {
		idx = a;
		val = b;
	}
	bool operator<(const pos&io) {
		return val < io.val;
	}
};

struct qwer {
	int from, to;
	int cost;
	qwer() {};
	qwer(int a, int b, int c) {
		from = a;
		to = b;
		cost = c;
	}
	bool operator<(const qwer&ioo)const {
		return cost > ioo.cost;
	}
};

int n;
pos x[100010];
pos y[100010];
pos z[100010];
int ix = 1, iy = 1, iz = 1;
int table[100010] = { 0 };
std::priority_queue<qwer>q;

int find(int x) {
	if (table[x] == x)return x;
	return table[x] = find(table[x]);
}

int absx(int x) {
	return x > 0 ? x : -x;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		x[i] = pos(i, a);
		y[i] = pos(i, b);
		z[i] = pos(i, c);
		table[i] = i;
	}
	std::sort(x + 1, x + 1 + n);
	std::sort(y + 1, y + 1 + n);
	std::sort(z + 1, z + 1 + n);
	for (int edge = 1; edge < n; edge++) {
		q.push(qwer(x[edge].idx, x[edge + 1].idx, (x[edge + 1].val - x[edge].val)));
		q.push(qwer(y[edge].idx, y[edge + 1].idx, (y[edge + 1].val - y[edge].val)));
		q.push(qwer(z[edge].idx, z[edge + 1].idx, (z[edge + 1].val - z[edge].val)));
	}
	int sum = 0;
	int cnt = 0;
	while (!q.empty()) {
		if (cnt == n - 1)break;
		qwer now = q.top();
		q.pop();
		if (find(now.from) == find(now.to))continue;
		sum += now.cost;
		cnt++;
		table[find(now.from)] = find(now.to);
	}
	printf("%d\n", sum);
	return 0;
}