#include<stdio.h>

int map[1010][1010] = {};
int A[1010][1010] = {};

int main() {
	int H, W, N, x, y;
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 0; i<H; i++) {
		for (int j = 0; j<W; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	map[0][0] = N - 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			map[i + 1][j] += (map[i][j] + (1 ^ A[i][j])) / 2;
			map[i][j + 1] += (map[i][j] + (0 ^ A[i][j])) / 2;
			A[i][j] ^= (map[i][j] & 1);
			map[i][j] = A[i][j];
		}
	}
	x = 0; y = 0;
	while (x < H && y < W) {
		if (x < 0 || y < 0) {
			x = -1; y = -1;
			return 0;
		}
		int temp = map[x][y];
		x += (temp ^ 1);
		y += (temp ^ 0);
	}
	x++; y++;
	printf("%d %d\n", x, y);
	return 0;
}
