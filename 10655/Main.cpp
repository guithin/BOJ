#include<stdio.h>
#include<queue>

int absx(int x) {
	return x > 0 ? x : -x;
}

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a;
		y = b;
	}
};

pos inp[100010];
int sub[100010] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inp[i].x, &inp[i].y);
		if (i - 1) {
			sub[i] = absx(inp[i].x - inp[i - 1].x) + absx(inp[i].y - inp[i - 1].y);
			tot += sub[i];
		}
	}
	int mini = 1 << 30;
	for (int i = 2; i < n; i++) {
		int sum = tot;
		sum -= sub[i];
		sum -= sub[i + 1];
		sum += absx(inp[i + 1].x - inp[i - 1].x) + absx(inp[i + 1].y - inp[i - 1].y);
		if (sum < mini) {
			mini = sum;
		}
	}
	printf("%d\n", mini);
	return 0;
}