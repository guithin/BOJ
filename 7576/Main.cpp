#include<stdio.h>
#include<queue>
using namespace std;

struct pos {
	int x;
	int y;
};

queue <pos> q;
queue <pos> in;
int map[1010][1010] = { 0 };
bool visit[1010][1010] = { 0 };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				map[i][j] = 0;
				visit[i][j] = true;
				pos temp;
				temp.x = i;
				temp.y = j;
				q.push(temp);
			}
		}
	}

/*	while(in.size()!=0) {
		int ix = in.front().x;
		int iy = in.front().y;
		in.pop();
		visit[ix][iy] = true;
		map[ix][iy] = 0;
		pos temp;
		temp.x = ix;
		temp.y = iy;
		q.push(temp);*/
		while (q.size() != 0) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int k = 0; k < 4; k++) {
				if (x + dx[k]<1 || x + dx[k]>n || y + dy[k]<1 || y + dy[k]>m)continue;
				if (visit[x + dx[k]][y + dy[k]] == true)continue;
				if (map[x + dx[k]][y + dy[k]] == -1)continue;
				if (map[x + dx[k]][y + dy[k]] == 0 || map[x + dx[k]][y + dy[k]] > map[x][y] + 1)
					map[x + dx[k]][y + dy[k]] = map[x][y] + 1;
				pos input;
				input.x = x + dx[k];
				input.y = y + dy[k];
				q.push(input);
				visit[x + dx[k]][y + dy[k]] = true;
			}
/*			for (int N = 1; N <= n; N++) {
				for (int M = 1; M <= m; M++) {
					printf("\t%d ", map[N][M]);
				}
				printf("\n");
			}
			printf("\n");
			getchar();*/
//		}
	}
		
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == false && map[i][j]!=-1) {
				printf("-1\n");
				return 0;
			}
			if (max < map[i][j])
				max = map[i][j];
		}
	}
	printf("%d\n", max);
	return 0;
}