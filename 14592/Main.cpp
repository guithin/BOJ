#include<stdio.h>
#include<algorithm>

struct pos {
	int s, l, c, idx;
	pos() {};
	pos(int a, int b, int _c, int d) {
		s = a; l = b; c = _c; idx = d;
	}
	bool operator<(const pos&io)const {
		if (s != io.s)return s > io.s;
		if (l != io.l)return l < io.l;
		return c < io.c;
	}
};

int n;
pos inp[1000010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &inp[i].s, &inp[i].l, &inp[i].c);
		inp[i].idx = i;
	}
	std::sort(inp + 1, inp + 1 + n);
	printf("%d\n", inp[1].idx);
	return 0;
}