#include<stdio.h>

int n, m;
int ver[1000010] = { 0 };
int rank[1000010] = { 0 };
int cnt = 0;

int find(int v) {
	if (ver[v] == v)return v;
	return find(ver[v]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (rank[u] > rank[v])
		ver[v] = u;
	else if (rank[u] < rank[v]) {
		ver[u] = v;
	}
	else {
		ver[u] = v;
		rank[v]++;
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ver[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int v, u;
			scanf("%d %d", &v, &u);
			uni(u, v);
		}
		else {
			int v, u;
			scanf("%d %d", &v, &u);
			if (find(u) == find(v))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}