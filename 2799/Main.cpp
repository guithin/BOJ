#include<stdio.h>
char map[1000][1000] = { 0 };
int check[110] = { 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int j = 1; j <= 5 * n + 1; j++) {
		scanf("%s", map[j]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[5 * i - 3][5 * j - 3] == '.')
				check[0]++;
			else if (map[5 * i - 2][5 * j - 3] == '.')
				check[1]++;
			else if (map[5 * i - 1][5 * j - 3] == '.')
				check[2]++;
			else if (map[5 * i][5 * j - 3] == '.')
				check[3]++;
			else
				check[4]++;
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d ", check[i]);
	}
	printf("\n");
	return 0;
}