#include<stdio.h>
#include<algorithm>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int map[30][30];
bool check[30][30];
int temp = 0;
void dfs(int x,int y) {
//	printf("%d %d\n", x, y);
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (check[x + dx[i]][y + dy[i]] == true) continue;
		if (map[x + dx[i]][y + dy[i]] != 0) {
			temp++;
			dfs(x + dx[i], y + dy[i]);
		}
	}
}



int main() {
	int n;
	int ans[1000] = { 0 };
	int c = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0)
				continue;
			else if (check[i][j] == true)
				continue;
			temp = 1;
//			printf("\n");
			dfs(i, j);
			if (temp != 0) {
				ans[c] = temp;
				temp = 0;
				c++;
			}
		}
	}
//	printf("\n");
	printf("%d\n", c - 1);
	sort(ans + 1, ans + c);
	for (int i = 1; i < c; i++) {
		printf("%d\n", ans[i]);
	}
/*	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}