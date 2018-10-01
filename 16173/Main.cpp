#include<bits/stdc++.h>
using namespace std;

int m[70][70];
int c[70][70];
queue<int>q;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	q.push(1); q.push(1); c[1][1] = 1;
	while (q.size()) {
		int nx = q.front(); q.pop();
		int ny = q.front(); q.pop();
		if (nx == n && ny == n) {
			printf("HaruHaru\n"); return 0;
		}
		if (nx + m[nx][ny] <= n && !c[nx + m[nx][ny]][ny]) {
			q.push(nx + m[nx][ny]); q.push(ny); c[nx + m[nx][ny]][ny] = 1;
		}
		if (ny + m[nx][ny] <= n && !c[nx][ny + m[nx][ny]]) {
			q.push(nx); q.push(ny + m[nx][ny]); c[nx][ny + m[nx][ny]] = 1;
		}
	}
	printf("Hing\n");
	return 0;
}