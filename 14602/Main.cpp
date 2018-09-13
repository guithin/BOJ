#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, w;
int mp[305][305];
int high = 1;
int tree[300000];

int find(int node, int nl, int nr, int fl) {
	if (nl == nr)return nl;
	int mid = (nl + nr) / 2;
	if (tree[node * 2] > fl) {
		return find(node * 2, nl, mid, fl);
	}
	else {
		return find(node * 2 + 1, mid + 1, nr, fl - tree[node * 2]);
	}
}

void pop(int x) {
	for (int cur = high + x; cur; cur >>= 1)
		tree[cur]--;
}

void push(int x) {
	for (int cur = high + x; cur; cur >>= 1)
		tree[cur]++;
}

void set_tree(int x) {
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= w; j++) {
			tree[high + mp[i + x - 1][j]]++;
		}
	}
	for (int cur = high - 1; cur; cur--) {
		tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
	}
}

int main() {
	while (high < 100000)high <<= 1;
	scanf("%d %d %d %d", &m, &n, &k, &w);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mp[i][j]);
		}
	}

	for (int i = 1; i <= m - w + 1; i++) {
		set_tree(i);
		for (int j = 1; j <= n - w + 1; j++) {
			if (j != 1) {
				for (int k = 1; k <= w; k++) {
					pop(mp[i + k - 1][j - 1]);
					push(mp[i + k - 1][j + w - 1]);
				}
			}
			printf("%d ", find(1, 0, high - 1, w*w / 2));
		}
		printf("\n");
	}
	return 0;
}