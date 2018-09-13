#include<stdio.h>

int input[510][510] = { 0 };
int map[510][510] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	map[1][1] = input[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			if (map[i][j] + input[i + 1][j] > map[i + 1][j])
				map[i + 1][j] = map[i][j] + input[i + 1][j];
			if (map[i][j] + input[i + 1][j + 1] > map[i + 1][j + 1])
				map[i + 1][j + 1] = map[i][j] + input[i + 1][j + 1];
		}
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		if (map[n][i] > maxi)
			maxi = map[n][i];
	}
	printf("%d\n", maxi);
	return 0;
}