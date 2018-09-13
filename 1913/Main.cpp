#include<stdio.h>

int map[1010][1010] = { 0 };
int n, k;
int ansx;
int ansy;

int main() {
	scanf("%d %d", &n, &k);
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;
	int i = 1;
	int num = 1;
	map[x][y] = i;
	i++;
	y--;
	while (1) {
		if (i >= n*n)break;
		for (int j = 0; j <= num; j++) {
			if (i == k) {
				ansx = x;
				ansy = y;
			}
			map[x][y] = i;
			i++;
			x++;
		}
		x--;
		y++;
		for (int j = 0; j <= num; j++) {
			if (i == k) {
				ansx = x;
				ansy = y;
			}
			map[x][y] = i;
			i++;
			y++;
		}
		y--;
		x--;
		for (int j = 0; j <= num; j++) {
			if (i == k) {
				ansx = x;
				ansy = y;
			}
			map[x][y] = i;
			i++;
			x--;
		}
		x++;
		y--;
		for (int j = 0; j <= num; j++) {
			if (i == k) {
				ansx = x;
				ansy = y;
			}
			map[x][y] = i;
			i++;
			y--;
		}
		num+=2;
//		y--;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	printf("%d %d\n", ansy, ansx);
	return 0;
}