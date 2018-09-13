#include<stdio.h>

int main() {
	char map[55][55] = {};
	bool chk[55][55] = {};
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] == 'Y'&&map[k][j] == 'Y')
					chk[i][j] = 1;
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (map[i][j] == 'Y')temp++;
			else if (chk[i][j])temp++;
		}
		if (temp > maxi)maxi = temp;
	}
	printf("%d\n", maxi);
	return 0;
}