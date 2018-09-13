#include<stdio.h>
#include<queue>
using namespace std;

struct pos {
	int x;
	int y;
	int z;
};

queue <pos> que;
int map[110][110][110] = { 0 };
bool check[110][110][110] = { 0 };
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

int main() {
	int n, m, h;
	int max = -1;
	scanf("%d %d %d", &m, &n, &h);
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 1) {
					pos temp;
					temp.x = i;
					temp.y = j;
					temp.z = k;
					que.push(temp);
					map[i][j][k] = 0;
					check[i][j][k] = true;
				}
			}
		}
	}
	while (que.size() != 0) {
		int x = que.front().x;
		int y = que.front().y;
		int z = que.front().z;
		que.pop();
		if (max < map[x][y][z])
			max = map[x][y][z];
		for (int i = 0; i < 6; i++) {
			if (x + dx[i]<1 || x + dx[i]>n || y + dy[i]<1 || y + dy[i]>m || z + dz[i]<1 || z + dz[i]>h)continue;
			if (check[x + dx[i]][y + dy[i]][z + dz[i]] == true)continue;
			if (map[x + dx[i]][y + dy[i]][z + dz[i]] == -1)continue;
			if (map[x + dx[i]][y + dy[i]][z + dz[i]] > map[x][y][z] + 1|| map[x + dx[i]][y + dy[i]][z + dz[i]]==0)
				map[x + dx[i]][y + dy[i]][z + dz[i]] = map[x][y][z] + 1;
			check[x + dx[i]][y + dy[i]][z + dz[i]] = true;
			pos input;
			input.x = x + dx[i];
			input.y = y + dy[i];
			input.z = z + dz[i];
			que.push(input);
		}
	}

/*	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d ", map[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}*/

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= h; k++) {
				if (check[i][j][k] == false && map[i][j][k] != -1) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%d\n", max);
	return 0;
}