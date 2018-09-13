#include<stdio.h>
#include<memory.h>

int map[15][15] = { 0 };
bool ans = false;

bool check(int x, int y) {
	x /= 3;
	y /= 3;
	x *= 3;
	y *= 3;
	bool asdf[15] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (asdf[map[x + i][y + j]] && map[x + i][y + j] != 0)
				return false;
			asdf[map[x + i][y + j]] = true;
		}
	}
	return true;
}

void back(int cur) {
/*	printf("%d\n", cur);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	getchar();*/
	if (ans)return;
	if (cur == 81) {
		for (int is = 0; is < 9; is += 3) {
			for (int js = 0; js < 9; js += 3) {
				bool chk[15] = { 0 };
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (chk[map[is + i][js + j]])return;
						chk[map[is + i][js + j]] = true;
					}
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		ans = true;
//		printf("\n");
		return;
	}
	int x = cur / 9;
	int y = cur % 9;
	if (!map[x][y]) {
		for (int i = 1; i <= 9; i++) {
			bool flag = false;
			for (int j = 0; j < 9; j++) {
				if (map[x][j] == i) {
					flag = true;
					break;
				}
			}
			if (flag)continue;
			for (int j = 0; j < 9; j++) {
				if (map[j][y] == i) {
					flag = true;
					break;
				}
			}
			if (flag)continue;
			map[x][y] = i;
			if (check(x, y) == false) {
				map[x][y] = 0;
				continue;
			}
			back(cur + 1);
			map[x][y] = 0;
		}
	}
	else
		back(cur + 1);
}

int main() {
	int t = 1;
//	scanf("%d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		back(0);
	}
	return 0;
}