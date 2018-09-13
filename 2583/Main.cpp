#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

struct pos {
	int x;
	int y;
};

queue <pos> que;
int map[110][110] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int area[1000000] = { 0 };
int idx = 0;

int main() {
	int n, m, k;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 1; i <= k; i++) {
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for (int j = sx; j < ex; j++) {
			for (int k = sy; k < ey; k++) {
				map[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				pos temp;
				temp.x = i;
				temp.y = j;
				que.push(temp);
				int areatemp = 1;
				while (que.size() != 0) {
					int x = que.front().x;
					int y = que.front().y;
					que.pop();
					for (int i = 0; i < 4; i++) {
						if (x + dx[i]<0 || x + dx[i]>=n || y + dy[i]<0 || y + dy[i]>=m)continue;
						if (map[x + dx[i]][y + dy[i]] == 1)continue;
						map[x + dx[i]][y + dy[i]] = 1;
						areatemp++;
						pos input;
						input.x = x + dx[i];
						input.y = y + dy[i];
						que.push(input);
					}
				}
				area[idx] = areatemp;
				idx++;
			}
		}
	}
	sort(area, area + idx);
	printf("%d\n", idx);
	for (int i = 0; i < idx; i++) {
		printf("%d ", area[i]);
	}
	printf("\n");

	return 0;
}