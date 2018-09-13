#include <iostream>
#include <queue>
using namespace std;

class pos {
public: int x,y;
		pos(int a, int b) :x(a), y(b) {};
};

int T, N, M, K;
queue<pos> q;
int map[55][55];
bool chk[55][55];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int bfs() {
	int nb = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 1 && chk[i][j] == false) {
				q.push(pos(i, j));
				chk[i][j] = true;
				while (!q.empty()) {
					int nx = q.front().x;
					int ny = q.front().y;
					q.pop();
					for (int l = 0; l < 4; l++){
					int mx = nx + dx[l];
					int my = ny + dy[l];
						if (mx < 0 || my < 0 || mx >= N  || my >= M) continue;
						if (map[mx][my] != 1) continue;
						if (chk[mx][my] == true) continue;
						q.push(pos(mx, my));
						chk[mx][my] = true;
					}
				}
				nb++;
			}
		}
	}
	return nb;
}

void set() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = 0;
			chk[i][j] = false;
		}
	}
}


int main() {
	int a, b;
	cin >> T;
	while (T--) {
		cin>> N >> M >> K;
		for (int i = 0; i < K; i++){
			cin >> a >> b;
			map[a][b] = 1;
		}
		cout << bfs() << '\n';
		set();
	}
	return 0;
}