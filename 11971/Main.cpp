#include<stdio.h>
#include<vector>

struct pos {
	int len, v;
	pos() {};
	pos(int a, int b) {
		len = a;
		v = b;
	}
};

int n, m;
std::vector<pos>nvec;
std::vector<pos>mvec;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		nvec.push_back(pos(a, b));
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		mvec.push_back(pos(a, b));
	}
	int now1 = 0;
	int temp1 = 0;
	int idx1 = 0;
	int now2 = 0;
	int temp2 = 0;
	int idx2 = 0;
	int ans = 0;
	while (1) {
		now1++;
		if (now1 > nvec[idx1].len) {
			now1 = 1;
			idx1++;
		}
		if (idx1 == nvec.size())break;
		now2++;
		if (now2 > mvec[idx2].len) {
			now2 = 1;
			idx2++;
		}
		if (mvec[idx2].v - nvec[idx1].v > ans)
			ans = mvec[idx2].v - nvec[idx1].v;
	}
	printf("%d\n", ans);
	return 0;
}