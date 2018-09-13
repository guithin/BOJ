#include<stdio.h>
#include<memory.h>

int n, m;
int high = 1;
int tree_max[400010] = { 0 };
int tree_min[400010] = { 0 };
int inf = 1800000000;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int find_max(int node, int start, int end, int l, int r) {
	if (start > r || end < l)return -inf;
	if (start == end)return tree_max[node];
	if (start >= l&&r >= end)return tree_max[node];
	int mid = (start + end) >> 1;
	return max(find_max(node << 1, start, mid, l, r), find_max((node << 1) + 1, mid + 1, end, l, r));
}

int find_min(int node, int start, int end, int l, int r) {
	if (start > r || end < l)return inf;
	if (start == end)return tree_min[node];
	if (start >= l&&r >= end)return tree_min[node];
	int mid = (start + end) >> 1;
	return min(find_min(node << 1, start, mid, l, r), find_min((node << 1) + 1, mid + 1, end, l, r));
}

int main() {
	scanf("%d %d", &n, &m);
	memset(tree_min, 60, sizeof(tree_min));
	memset(tree_max, -60, sizeof(tree_max));
	while (high < n)high <<= 1;
	for (int i = high; i < high + n; i++) {
		scanf("%d", &tree_max[i]);
		tree_min[i] = tree_max[i];
	}
	//setup
	for (int i = high - 1; i > 0; i--) {
		tree_max[i] = max(tree_max[i << 1], tree_max[(i << 1) + 1]);
		tree_min[i] = min(tree_min[i << 1], tree_min[(i << 1) + 1]);
	}
	for (int cur = 1; cur <= m; cur++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d %d\n", find_min(1, 1, high, s, e), find_max(1, 1, high, s, e));
	}
	return 0;
}