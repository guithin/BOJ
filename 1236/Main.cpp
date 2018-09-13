#include<stdio.h>

char map[55][55] = { 0 };
int n, m;
bool tablen[55] = { 0 };
bool tablem[55] = { 0 };

void e(int x, int y) {
	tablen[x] = 1;
	tablem[y] = 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 'X') {
				e(i, j);
			}
		}
	}
	int cnt2 = 0;
	int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		if (!tablen[i])cnt1++;
	}
	for (int i = 1; i <= m; i++) {
		if (!tablem[i])cnt2++;
	}
	printf("%d\n", cnt1 > cnt2 ? cnt1 : cnt2);
	return 0;
}