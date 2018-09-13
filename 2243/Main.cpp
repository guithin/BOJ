#include<stdio.h>

int tree[3000000] = { 0 };
int high = 1;

void set(int x, int b) {
	tree[x] += b;
	if (tree[x] < 0)tree[x] = 0;
	for (int i = x / 2; i >= 1; i >>= 1) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

int find(int node, int x) {
	tree[node]--;
	if (node >= high) {
		return node;
	}
	if (tree[node * 2] >= x) {
		return find(node * 2, x);
	}
	else {
		return find(node * 2 + 1, x - tree[node * 2]);
	}
}

int main() {
	while (high < 1000000)high <<= 1;
	for (int i = high - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int mode;
		scanf("%d", &mode);
		if (mode == 2) {
			int a, b;
			scanf("%d %d", &a, &b);
			set(high + a - 1, b);
		}
		else {
			int a;
			scanf("%d", &a);
			if (tree[1] < a)continue;
			printf("%d\n", find(1, a) - high + 1);
		}
	}
	return 0;
}