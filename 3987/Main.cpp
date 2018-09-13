#include<stdio.h>

int map[510][510] = { 0 };
int visit[510][510][2] = { 0 };
int dd[4] = { 1, 2, 3, 4 };
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};



int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("\n");
		for (int j = 1; j <= m; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	int idx = 0;
	int x, y;
	int xx, yy;
	scanf("%d %d", &xx, &yy);
	int maxi = -1;
	for (int i = 0; i < 4; i++) {
		x = xx;
		y = yy;
		int cnt = 0;
		visit[x][y][0] = 1;
		int now = dd[i];
		while (1) {
			if (x<1 || x>n || y<1 || y>m)break;
			if (visit[x][y][0] == 1) {
				if (visit[x][y][1] == now) {
					if (dd[i] == 1)printf("U\n");
					else if (dd[i] == 2)printf("R\n");
					else if (dd[i] == 3)printf("D\n");
					else printf("L\n");
					printf("Voyager\n");
					return 0;
				}
			}
			cnt++;
			if (map[x][y] == '/') {
				if (now == 1)now = 2;
				else if (now == 2)now = 1;
				else if (now == 3)now = 4;
				else now = 3;
			}
			else if (map[x][y] == '\\') {
				if (now == 1)now = 4;
				else if (now == 4)now = 1;
				else if (now == 2)now = 3;
				else now = 2;
			}
			else if (map[x][y] == 'C') {
				cnt--;
				break;
			}
			visit[x][y][1] = now;
			x += dx[now - 1];
			y += dy[now - 1];
		}
		if (maxi < cnt) {
			maxi = cnt;
			idx = dd[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				visit[i][j][0] = 0;
				visit[i][j][1] = 0;
			}
		}
	}
	if (idx == 1)printf("U\n");
	else if (idx == 2)printf("R\n");
	else if (idx == 3)printf("D\n");
	else printf("L\n");
	printf("%d\n", maxi);
	return 0;
}