#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;

struct pos {
	int i, j;
	pos() {}
	pos(int a, int b) {
		i = a; j = b;
	}
};

char ma[1010][1010];
int chk[1010][1010];
int cnt = 1;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", ma[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chk[i][j])continue;
			int ii = i, jj = j;
			stack<pos>stk;
			while (!chk[ii][jj]) {
				stk.push(pos(ii, jj));
				chk[ii][jj] = cnt;
				if (ma[ii][jj] == 'N')ii--;
				else if (ma[ii][jj] == 'S')ii++;
				else if (ma[ii][jj] == 'W')jj--;
				else jj++;
			}
			if (chk[ii][jj] == cnt)cnt++;
			else {
				while (stk.size()) {
					chk[stk.top().i][stk.top().j] = cnt - 1;
					stk.pop();
				}
			}
		}
	}
	printf("%d\n", cnt - 1);
	return 0;
}