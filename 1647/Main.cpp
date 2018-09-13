#include<stdio.h>
#include<algorithm>

int n, m;
int ver[100010] = { 0 };

int find(int v) {
	if (ver[v] == v)return v;
	return ver[v] = find(ver[v]);
}

struct pos {
	int start;
	int end;
	int weight;
	bool operator <(const pos &o)const
	{
		return weight < o.weight;
	}
};

pos edge[1000010];

int main() {
	int w = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ver[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pos input;
		input.start = a;
		input.end = b;
		input.weight = c;
		edge[i] = input;
	}
	std::sort(edge + 1, edge + m + 1);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, we;
		u = edge[i].start;
		v = edge[i].end;
		we = edge[i].weight;
		if (find(u) != find(v)) {
			w += we;
			ver[find(u)] = v;
			cnt++;
		}
		if (cnt >= n - 2)break;
	}
	printf("%d\n", w);
	return 0;
}