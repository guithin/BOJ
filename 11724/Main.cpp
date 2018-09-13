#include<stdio.h>

int n, m;
int ver[1010] = { 0 };
int cnt = 0;

int find(int v) {
	if (ver[v] == v)return v;
	return find(ver[v]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ver[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		ver[find(u)] = find(v);
	}
	for (int i = 1; i <= n; i++) {
		if (ver[i] == i) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}