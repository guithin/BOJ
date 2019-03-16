#include<bits/stdc++.h>
using namespace std;

struct pos {
	int v, l;
	pos() {};
	pos(int a, int b) {
		v = a; l = b;
	}
};

int n;
vector<pos>vec[100010];
int a[100010];
int b[100010];
bool chk[100010];

void dfs(int idx) {
	chk[idx] = true;
	for (auto i : vec[idx]) {
		if (!chk[i.v]) {
			dfs(i.v);
			if (a[idx] < a[i.v] + i.l) {
				b[idx] = a[idx];
				a[idx] = a[i.v] + i.l;
			}
			else if (b[idx] < a[i.v] + i.l)b[idx] = a[i.v] + i.l;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		while (1) {
			int u, v;
			scanf("%d", &u); if (u == -1)break;
			scanf("%d", &v);
			vec[k].push_back(pos(u, v));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!chk[i])dfs(i);
		ans = max(ans, a[i] + b[i]);
	}
	printf("%d\n", ans);
	return 0;
}