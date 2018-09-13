#include<stdio.h>
#include<queue>
using namespace std;

bool flag = false;
int n, m;
int map[310][310] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int day = 0;

struct pos {
	int x;
	int y;
};

queue <pos> q;
//queue <pos> chk;

//queue <int> qx;
//queue <int> qy;


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			map[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		bool it = false;
		bool check2[310][310] = { 0 };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (it == true && map[i][j] != 0 && check2[i][j] != true) {
					flag = true;
					break;
				}
				else if (it == true)continue;
				if (map[i][j] != 0) {
					check2[i][j] = true;
					it = true;
					pos temp;
					temp.x = i;
					temp.y = j;
					q.push(temp);
//					chk.push(temp);
					while (q.size() != 0) {
						int x = q.front().x;
						int y = q.front().y;
						q.pop();
						for (int k = 0; k < 4; k++) {
							if (x + dx[k]<1 || x + dx[k]>n || y + dy[k]<1 || y + dy[k]>m) continue;
							if (check2[x + dx[k]][y + dy[k]] == true)continue;
							if (map[x + dx[k]][y + dy[k]] == 0)continue;
							check2[x+dx[k]][y+dy[k]] = true;
							pos temp2;
							temp2.x = x + dx[k];
							temp2.y = y + dy[k];
							q.push(temp2);
//							chk.push(temp2);

						}
					}
				}
			}
			if (flag == true)
				break;
		}
		if (it == false) {
			printf("0\n");
			return 0;
		}
		if (flag == true)break;

/*		while (chk.size() != 0) {
			int x = chk.front().x;
			int y = chk.front().y;
			chk.pop();
			for (int i = 0; i < 4; i++) {
				if (check2[x + dx[i]][y + dy[i]] == 0 && map[x][y] != 0)
					map[x][y]--;
			}
		}*/
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						if (check2[i + dx[k]][j + dy[k]])continue;
						if (map[i + dx[k]][j + dy[k]] == 0 && map[i][j] != 0) {
							map[i][j]--;
						}
					}
				}
			}
		}
		day++;
//		printf("%d\n", day);
	}
	printf("%d\n", day);
	return 0;
}