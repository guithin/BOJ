#include<stdio.h>

struct pos {
	int x;
	int y;
	int r;
	pos() {};
	pos(int a, int b) {
		x = a;
		y = b;
	}
};

pos input[55];
int x1, x2, y1, y2;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		int cnt = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &input[i].x, &input[i].y, &input[i].r);
			if (((input[i].x - x1)*(input[i].x - x1) + (input[i].y - y1)*(input[i].y - y1) < input[i].r*input[i].r)||(input[i].x - x2)*(input[i].x - x2) + (input[i].y - y2)*(input[i].y - y2) < input[i].r*input[i].r) {
				if (((input[i].x - x1)*(input[i].x - x1) + (input[i].y - y1)*(input[i].y - y1) < input[i].r*input[i].r) && (input[i].x - x2)*(input[i].x - x2) + (input[i].y - y2)*(input[i].y - y2) < input[i].r*input[i].r)continue;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}