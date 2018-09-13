#include<stdio.h>
#include<vector>
#include<queue>

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a;
		y = b;
	}
};

int n;
int map[110][110] = { 0 };
char mapc[110][110] = { 0 };
std::vector<pos>vec;
int dx[8] = { 0,0,1,-1, 1, 1, -1, -1};
int dy[8] = { 1,-1,0,0, 1, -1, 1, -1 };
int startx, starty;

bool isok(int l, int h) {
	std::queue<pos>q;
	bool chk[110][110] = { 0 };
	if (map[startx][starty] >= l&&map[startx][starty] <= h) {
		q.push(pos(startx, starty));
		chk[startx][starty] = true;
	}
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			if (now.x + dx[i]<1 || now.x + dx[i]>n || now.y + dy[i]<1 || now.y + dy[i]>n)continue;
			if (chk[now.x + dx[i]][now.y + dy[i]])continue;
			if (map[now.x + dx[i]][now.y + dy[i]] >= l&&map[now.x + dx[i]][now.y + dy[i]] <= h) {
				chk[now.x + dx[i]][now.y + dy[i]] = true;
				q.push(pos(now.x + dx[i], now.y + dy[i]));
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		if (!chk[vec[i].x][vec[i].y]) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char qwerqwer;
			scanf(" %c", &qwerqwer);
			if (qwerqwer == 'P') {
				startx = i;
				starty = j;
			}
			if (qwerqwer == 'K') {
				vec.push_back(pos(i, j));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int mini = 10000000;
	int maxi = -1;
	for (int i = 0; i < vec.size(); i++) {
		int temp = map[vec[i].x][vec[i].y];
		if (temp < mini) {
			mini = temp;
		}
		if (temp > maxi) {
			maxi = temp;
		}
	}
	int l = -1;
	int r = 0;
	int ans = 10000000;
/*	while (1) {
		if (r > 1000000 || l > mini)break;
		if (isok(l, r)) {
			if (ans > r - l) {
				ans = r - l;
			}
			l++;
		}
		else {
			r++;
		}
	}*/
	while (1) {
		if (r > 1000000 || l > mini)break;
		l++;
		int tl = r;
		int tr = 1000000;
		while (tl <= tr) {
			int mid = (tl + tr) / 2;
			if (isok(l, mid)) {
				tr = mid - 1;
			}
			else {
				tl = mid + 1;
			}
		}
		r = tl;
		tl = l;
		tr = r;
		while (tl <= tr) {
			int mid = (tl + tr) / 2;
			if (isok(mid, r)) {
				tl = mid + 1;
			}
			else {
				tr = mid - 1;
			}
		}
		l = tr;
		if (r - l < ans)ans = r - l;
	}
	printf("%d\n", ans);
	return 0;
}