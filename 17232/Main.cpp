#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, t;
int k, a, b;

char ma[2][110][110];


int main() {
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &k, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%s", ma[t & 1][i] + 1);
	}

	while (t--) {
		int S = t & 1;
		int N = S ^ 1;
		for (int i = 1; i <= n; i++) {

			int num = 0;
			for (int q = i - k; q <= i + k; q++) {
				for (int w = 1 - k; w <= 1 + k; w++) {
					if (q<1 || q>n || w<1 || w>m)continue;
					num += ma[N][q][w] == '*';
				}
			}

			for (int j = 1; j <= m; j++) {
				int value = num - (ma[N][i][j] == '*');
				if ((value < a || value > b) && ma[N][i][j] == '*') {
					ma[S][i][j] = '.';
				}
				else if (a < value && value <= b && ma[N][i][j] == '.') {
					ma[S][i][j] = '*';
				}
				else {
					ma[S][i][j] = ma[N][i][j];
				}

				for (int q = i - k; q <= i + k; q++) {
					if (1 <= q && q <= n && 1 <= j - k && j - k <= m)
						num -= ma[N][q][j - k] == '*';
					if (1 <= q && q <= n && 1 <= j + k + 1 && j + k + 1 <= m)
						num += ma[N][q][j + k + 1] == '*';
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%s\n", ma[0][i] + 1);
	}
	return 0;
}