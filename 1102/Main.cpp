#include<stdio.h>
#include<memory.h>

const int inf = 100000000;
int n, p;
int map[20][20] = { 0 };
int dp[150000] = { 0 };
int stus, num;
int ans = inf;

int back(int now, int bit) {
	if (bit == stus) {
		int mmin = inf;
		for (int i = 1; i <= n; i++) {
			if (bit&(1 << i)) {
				if (mmin > map[i][now])
					mmin = map[i][now];
			}
		}
		dp[bit | (1 << now)] = mmin;
	}
	int mini = inf;
	if (dp[bit] == dp[149999]) {
		for (int i = 1; i <= n; i++) {
			if (bit&(1 << i)) {
				if ((stus&(1 << i)) == 0) {
					back(i, bit - (1 << i));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (bit&(1 << i)) {
			if (mini > map[i][now])
				mini = map[i][now];
		}
	}

	if (dp[bit | (1 << now)] > dp[bit] + mini) {
		dp[bit | (1 << now)] = dp[bit] + mini;
	}
//	dp[bit | (1 << now)] = dp[bit] + mini;

	return dp[bit | (1 << now)];
}

void back2(int cur, int bit, int t) {
	if (cur == n + 2)return;
	if (t + 1 == p) {
/*		if (stus&(1 << cur)) {
			back2(cur + 1, bit, t);
		}
		else {*/
			int qwer = inf;
			for (int i = 1; i <= n; i++) {
				if (bit&(1 << i))continue;
				int temp = back(i, bit);
				if (temp < qwer)
					qwer = temp;
			}
			if (ans > qwer)
				ans = qwer;
//		}
		return;
	}
	if (stus&(1 << cur))
		back2(cur + 1, bit, t);
	else {
		back2(cur + 1, bit, t);
		back2(cur + 1, bit | (1 << cur), t + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf(" ");
	for (int i = 1; i <= n; i++) {
		char c = getchar();
		if (c == 'Y') {
			stus |= (1 << i);
			num++;
		}
	}
	scanf("%d", &p);
	if (num >= p) {
		printf("0\n");
		return 0;
	}
	if (num == 0) {
		printf("-1\n");
		return 0;
	}

	memset(dp, 40, sizeof(dp));
	dp[stus] = 0;
	back2(1, stus, num);
	printf("%d\n", ans);
	return 0;
}