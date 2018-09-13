#include<stdio.h>

char spot[110][110];
bool chkspot[110][5];
char plain[110][110];
bool chkplain[110][5];

int main() {
	int n, m;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", spot[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", plain[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			if (spot[j][i] == 'A')chkspot[i][1] = true;
			if (spot[j][i] == 'T')chkspot[i][2] = true;
			if (spot[j][i] == 'C')chkspot[i][3] = true;
			if (spot[j][i] == 'G')chkspot[i][4] = true;

			if (plain[j][i] == 'A')chkplain[i][1] = true;
			if (plain[j][i] == 'T')chkplain[i][2] = true;
			if (plain[j][i] == 'C')chkplain[i][3] = true;
			if (plain[j][i] == 'G')chkplain[i][4] = true;
		}
		bool flag = true;
		for (int j = 1; j <= 4; j++) {
			if (chkspot[i][j] == true && chkplain[i][j] == true)flag = false;
		}
		if (flag)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}