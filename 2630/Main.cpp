#include<stdio.h>
int n;
int map[200][200] = { 0 };
int c0 = 0;
int c1 = 0;

void div(int xs, int xe, int ys, int ye) {
	bool flag = true;
	for (int i = xs + 1; i <= xe; i++) {
		for (int j = ys + 1; j <= ye; j++) {
			if (map[i][j] != map[xs + 1][ys + 1]) {
				flag = false;
				break;
			}
		}
		if (flag == false)break;
	}
	if (flag == true) {
		if (map[xs + 1][ys + 1] == 1)
			c1++;
		else
			c0++;
		return;
	}
	div(xs, (xe + xs) / 2, ys, (ys + ye) / 2);
	div(xs, (xe + xs) / 2, (ys + ye) / 2, ye);
	div((xe + xs) / 2, xe, ys, (ys + ye) / 2);
	div((xe + xs) / 2, xe, (ys + ye) / 2, ye);

}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	div(0, n, 0, n);
	printf("%d\n%d\n", c0, c1);
	return 0;
}