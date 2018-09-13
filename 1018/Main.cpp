#include<stdio.h>

char map[55][55] = { 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", map[i]);
	}
	int chk = 100000000;
	for (int i = 1; i <= n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int temp1 = 0;
			int temp2 = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if ((i + k + j + l) % 2 == 0 && map[i + k][j + l] != 'W') {
						temp1++;
					}
					if ((i + k + j + l) % 2 == 1 && map[i + k][j + l] != 'B') {
						temp1++;
					}

					if ((i + k + j + l) % 2 == 0 && map[i + k][j + l] != 'B') {
						temp2++;
					}
					if ((i + k + j + l) % 2 == 1 && map[i + k][j + l] != 'W') {
						temp2++;
					}
				}
			}
			if (temp1 < chk)chk = temp1;
			if (temp2 < chk)chk = temp2;
		}
	}
	printf("%d\n", chk);
	return 0;
}