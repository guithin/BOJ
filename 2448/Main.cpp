#include<bits/stdc++.h>
using namespace std;

int m[6200][3100];

void func(int n, int x, int y) {
	if (n == 3) {
		m[x][y] = 1;
		m[x - 1][y + 1] = m[x + 1][y + 1] = 1;
		for (int i = -2; i <= 2; i++) {
			m[x + i][y + 2] = 1;
		}
		return;
	}
	func(n / 2, x, y);
	func(n / 2, x - n / 2, y + n / 2);
	func(n / 2, x + n / 2, y + n / 2);
}

int main() {
	int n;
	scanf("%d", &n);
	func(n, n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 2 * n; j++) {
			if (m[j][i + 1])printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}