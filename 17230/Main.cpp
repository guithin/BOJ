#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include<set>
using namespace std;

int n, m, q;
set<int>st[100010];
int tree_max[400010];
int tree_min[400010];
int high = 1;

int get_min(int node, int nl, int nr, int fl, int fr) {
	if (fr < nl || nr < fl)return 1234567890;
	if (fl <= nl && nr <= fr)return tree_min[node];
	int mid = (nl + nr) / 2;
	return min(get_min(node * 2, nl, mid, fl, fr), get_min(node * 2 + 1, mid + 1, nr, fl, fr));
}
int get_max(int node, int nl, int nr, int fl, int fr) {
	if (fr < nl || nr < fl)return 0;
	if (fl <= nl && nr <= fr)return tree_max[node];
	int mid = (nl + nr) / 2;
	return max(get_max(node * 2, nl, mid, fl, fr), get_max(node * 2 + 1, mid + 1, nr, fl, fr));
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	memset(tree_min, 40, sizeof(tree_min));
	while (high < n)high <<= 1;
	for (int i = 0; i < n; i++) {
		tree_max[high + i] = i + 1;
		tree_min[high + i] = i + 1;
		st[i + 1].insert(i + 1);
	}
	for (int i = 1; i <= m; i++) {
		int q, w;
		scanf("%d %d", &q, &w);
		st[q].insert(w);
		tree_max[high + q - 1] = max(tree_max[high + q - 1], w);
		tree_min[high + q - 1] = min(tree_min[high + q - 1], w);
	}
	for (int i = high - 1; i; i--) {
		tree_max[i] = max(tree_max[i * 2], tree_max[i * 2 + 1]);
		tree_min[i] = min(tree_min[i * 2], tree_min[i * 2 + 1]);
	}
	while (q--) {
		int mode, a, b;
		scanf("%d %d %d", &mode, &a, &b);
		if (mode == 1) {
			int mini = get_min(1, 1, high, a, b);
			int maxi = get_max(1, 1, high, a, b);
			printf("%s\n", (a <= mini && b >= maxi) ? "YES" : "NO");
		}
		if (mode == 2) {
			auto it = st[a].find(b);
			if (it == st[a].begin()) {
				st[a].erase(it);
				tree_min[high + a - 1] = *st[a].begin();
				for (int i = (high + a - 1) / 2; i; i >>= 1) {
					tree_min[i] = min(tree_min[i * 2], tree_min[i * 2 + 1]);
				}
			}
			else if (b == *st[a].rbegin()) {
				st[a].erase(it);
				tree_max[high + a - 1] = *st[a].rbegin();
				for (int i = (high + a - 1) / 2; i; i >>= 1) {
					tree_max[i] = max(tree_max[i * 2], tree_max[i * 2 + 1]);
				}
			}
			else st[a].erase(it);
		}
		if (mode == 3) {
			st[a].insert(b);
			if (tree_min[high + a - 1] > b) {
				tree_min[high + a - 1] = b;
				for (int i = (high + a - 1) / 2; i; i >>= 1) {
					tree_min[i] = min(tree_min[i * 2], tree_min[i * 2 + 1]);
				}
			}
			else if (tree_max[high + a - 1] < b) {
				tree_max[high + a - 1] = b;
				for (int i = (high + a - 1) / 2; i; i >>= 1) {
					tree_max[i] = max(tree_max[i * 2], tree_max[i * 2 + 1]);
				}
			}
		}
	}
	return 0;
}