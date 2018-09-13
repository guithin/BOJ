#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	char str[55][55] = {};
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i] + 1);
	}
	int ans = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (i == 'M')continue;
		for (int j = 'A'; j <= 'Z'; j++) {
			if (i == j)continue;
			if (j == 'O')continue;
			int cnt = 0;
			for (int ii = 1; ii <= n; ii++) {
				for (int jj = 1; jj <= m; jj++) {
					if (str[ii][jj] == i) {
						if (ii >= 3 && str[ii - 1][jj] == j && str[ii - 2][jj] == j)cnt++;
						if (ii + 2 <= n && str[ii + 1][jj] == j && str[ii + 2][jj] == j)cnt++;
						if (jj >= 3 && str[ii][jj - 1] == j && str[ii][jj - 2] == j)cnt++;
						if (jj + 2 <= m && str[ii][jj + 1] == j && str[ii][jj + 2] == j)cnt++;
						if (ii >= 3 && jj >= 3 && str[ii - 1][jj - 1] == j && str[ii - 2][jj - 2] == j)cnt++;
						if (ii >= 3 && jj + 2 <= m && str[ii - 1][jj + 1] == j && str[ii - 2][jj + 2] == j)cnt++;
						if (ii + 2 <= n && jj >= 3 && str[ii + 1][jj - 1] == j && str[ii + 2][jj - 2] == j)cnt++;
						if (ii + 2 <= n && jj + 2 <= m && str[ii + 1][jj + 1] == j && str[ii + 2][jj + 2] == j)cnt++;
					}
				}
			}
			if (cnt > ans)ans = cnt;
		}
	}
	printf("%d\n", ans);
	return 0;
}