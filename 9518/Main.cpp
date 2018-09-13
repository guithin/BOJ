#include<stdio.h>

char input[100][100] = { 0 };
int map[100][100] = { 0 };
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("\n");
		for (int j = 1; j <= m; j++) {
			scanf("%c", &input[i][j]);
			if (input[i][j] == '.') map[i][j] = 0;
			else if(input[i][j]=='o') map[i][j] = 1;
		}
	}
	int sum = 0;
	int maxi = 0;
	int ii=1, jj=1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1)continue;
			int temp = 0;
			for (int k = 0; k < 8; k++) {
				if (map[i + dx[k]][j + dy[k]] == 1) {
					temp++;
				}
			}
			if (temp > maxi) {
				maxi = temp;
				ii = i;
				jj = j;
			}
		}
	}
	map[ii][jj] = 1;
	int suum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0)continue;
			int temp = 0;
			for (int k = 0; k < 8; k++) {
				if (map[i + dx[k]][j + dy[k]] == 1) {
					temp++;
				}
			}
			suum += temp;
		}
	}
	printf("%d\n", suum/2);
	return 0;
}