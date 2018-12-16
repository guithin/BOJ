#include<bits/stdc++.h>
using namespace std;
typedef unsigned int u_int;

struct pos {
	u_int bit;
	int bitcnt;
	pos() {};
	pos(u_int a, int b) {
		bit = a; bitcnt = b;
	}
};

int dp[15][2500];
char ma[15][15];
u_int comp[15];
vector<pos>lst;
u_int n, m;


void back(int x, u_int bit, int cnt) {
	if (x == m) {
		lst.push_back(pos(bit, cnt));
		return;
	}
	if (!(bit & 1))back(x + 1, (bit << 1) | 1, cnt + 1);
	back(x + 1, bit << 1, cnt);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(ma, 0, sizeof(ma));
		memset(comp, 0, sizeof(comp));
		lst.clear();
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", ma[i] + 1);
			for (int j = 1; j <= m; j++) {
				if (ma[i][j] == 'x')comp[i] |= (1 << j - 1);
			}
		}
		back(0, 0, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (auto j : lst) {
				for (auto k : lst) {
					if ((k.bit << 1)&j.bit)continue;
					if ((k.bit >> 1)&j.bit)continue;
					if (k.bit & comp[i])continue;
					dp[i][k.bit] = max(dp[i][k.bit], dp[i - 1][j.bit] + k.bitcnt);
					ans = max(ans, dp[i][k.bit]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}