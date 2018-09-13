#include<stdio.h>

int n, m;
int map[1010][1010] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int change(int x) {
	if (x == 0)return 3;
	if (x == 1)return 2;
	if (x == 2)return 1;
	if (x == 3)return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		map[i][0] = i;
	}
	for (int i = 1; i <= m; i++) {
		map[n + 1][i] = n + i;
	}
	for (int i = 1; i <= n; i++) {
		map[n - i + 1][m + 1] = m + n + i;
	}
	for (int i = 1; i <= m; i++) {
		map[0][m - i + 1] = 2 * n + m + i;
	}
	int vect, x, y;
	for (int i = 1; i <= n; i++) {
		x = i;
		y = 0;
		vect = 0;
		while (1) {
			if (x + dx[vect]<1 || x + dx[vect]>n || y + dy[vect]<1 || y + dy[vect]>m) {
				printf("%d ", map[x + dx[vect]][y + dy[vect]]);
				break;
			}
			x += dx[vect];
			y += dy[vect];
			if (map[x][y])vect = change(vect);
		}
	}
	for (int i = 1; i <= m; i++) {
		x = n + 1;
		y = i;
		vect = 3;
		while (1) {
			if (x + dx[vect]<1 || x + dx[vect]>n || y + dy[vect]<1 || y + dy[vect]>m) {
				printf("%d ", map[x + dx[vect]][y + dy[vect]]);
				break;
			}
			x += dx[vect];
			y += dy[vect];
			if (map[x][y])vect = change(vect);
		}
	}
	for (int i = 1; i <= n; i++) {
		x = n - i + 1;
		y = m + 1;
		vect = 1;
		while (1) {
			if (x + dx[vect]<1 || x + dx[vect]>n || y + dy[vect]<1 || y + dy[vect]>m) {
				printf("%d ", map[x + dx[vect]][y + dy[vect]]);
				break;
			}
			x += dx[vect];
			y += dy[vect];
			if (map[x][y])vect = change(vect);
		}
	}
	for (int i = 1; i <= m; i++) {
		x = 0;
		y = m - i + 1;
		vect = 2;
		while (1) {
			if (x + dx[vect]<1 || x + dx[vect]>n || y + dy[vect]<1 || y + dy[vect]>m) {
				printf("%d ", map[x + dx[vect]][y + dy[vect]]);
				break;
			}
			x += dx[vect];
			y += dy[vect];
			if (map[x][y])vect = change(vect);
		}
	}
	printf("\n");
	return 0;
}