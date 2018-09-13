#include<stdio.h>
const int last = 2 << 17;
struct node {
	int l, r;
	long long int value;
};

node tree[last];
void init(int now, int l, int r) {
	tree[now].l = l;
	tree[now].r = r;
	tree[now].value = 0;
	if (l != r) {
		init(now * 2, l, (l + r) / 2);
		init(now * 2 + 1, (l + r) / 2 + 1, r);
	}
}

void set(int target, long long int value) {
	if (tree[target].l == tree[target].r) {
		long long int tmp = tree[target].value;
		tree[target].value = value;
		set(target / 2, value - tmp);
	}
	else {
		tree[target].value += value;
		if (target != 1) {
			set(target / 2, value);
		}
	}
}

long long int get(int now, int start, int end) {
	if (start == tree[now].l && end == tree[now].r) {
		return tree[now].value;
	}
	else if (end <= tree[now * 2].r) {
		return get(now * 2, start, end);
	}
	else if (tree[now * 2 + 1].l <= start) {
		return get(now * 2 + 1, start, end);
	}
	else {
		return get(now * 2, start, tree[now * 2].r) + get(now * 2 + 1, tree[now * 2 + 1].l, end);
	}
}

int main() {
	int N, Q;
	init(1, 1, (2 << 16));
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		long long int a;
		scanf("%lld", &a);
		set((2 << 16) + i, a);
	}
	for (int i = 1; i <= Q; ++i) {
		int start, end, target;
		long long int value;
		scanf("%d %d %d %lld", &start, &end, &target, &value);
		if (start>end) {
			int temp = start;
			start = end;
			end = temp;
		}
		printf("%lld\n", get(1, start, end));
		set((2 << 16) + target - 1, value);
	}
}