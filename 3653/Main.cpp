#include<stdio.h>
#include<memory.h>
int high = 1;
int tree[8100000] = { 0 };
int wh[1000100] = { 0 };
int now;

int find(int node, int nl, int nr, int fl) {
	if (nr <= fl)return 0;
	if (nl > fl)return tree[node];
	int mid = (nl + nr) / 2;
	return find(node * 2, nl, mid, fl) + find(node * 2 + 1, mid + 1, nr, fl);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(tree, 0, sizeof(tree));
		memset(wh, 0, sizeof(wh));
		high = 1;
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			wh[n - i + 1] = i;
		}
		now = n + 1;
		while (high < n + m)high <<= 1;
		for (int i = 0; i < n; i++) {
			tree[high + i] = 1;
		}
		for (int i = high - 1; i >= 1; i--) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
		for (int i = 1; i <= m; i++) {
			int t;
			scanf("%d", &t);
			printf("%d\n", find(1, 1, high, wh[t]));
			int temp = wh[t];
			tree[high + wh[t] - 1] = 0;
			wh[t] = now++;
			tree[high + wh[t] - 1] = 1;
			for (int j = (high + temp - 1) / 2; j >= 1; j >>= 1) {
				tree[j] = tree[j * 2] + tree[j * 2 + 1];
			}
			for (int j = (high + wh[t] - 1) / 2; j >= 1; j >>= 1) {
				tree[j] = tree[j * 2] + tree[j * 2 + 1];
			}
		}
	}
	return 0;
}