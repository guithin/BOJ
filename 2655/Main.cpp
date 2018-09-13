#include<stdio.h>
#include<algorithm>

struct pos {
	int area, h, w, idx;
	pos() {};
	pos(int a, int b, int c, int d) {
		area = a; h = b; w = c; idx = d;
	}
	bool operator<(const pos&io)const {
		return area < io.area;
	}
};

int n;
pos inp[110] = {};
int dp[110] = { 0 };
int path[110] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &inp[i].area, &inp[i].h, &inp[i].w);
		inp[i].idx = i;
	}
	std::sort(inp + 1, inp + 1 + n);
	dp[1] = inp[1].h;
	for (int i = 1; i <= n; i++) {
		dp[i] = inp[i].h;
		for (int j = 1; j < i; j++) {
			if (inp[i].w >= inp[j].w&&dp[i] < dp[j] + inp[i].h) {
				dp[i] = dp[j] + inp[i].h;
				path[inp[i].idx] = inp[j].idx;
			}
		}
	}
	int maxi = -1;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (maxi < dp[i]) {
			maxi = dp[i];
			idx = inp[i].idx;
		}
	}
	path[0] = -1;
	int stack[10000] = { 0 };
	int ii = 0;
	while (path[idx] != -1) {
		stack[ii] = idx;
		idx = path[idx];
		ii++;
	}
	printf("%d\n", ii);
	for (int i = ii - 1; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	return 0;
}