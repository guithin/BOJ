#include<stdio.h>
#include<vector>
#include<memory.h>
using namespace std;

int n;
int node[200010];
int deep[200010];
int garo[200010];
int low[200010];
int big[200010];
bool chk[10010];
int cnt = 1;

void dfs(int x, int d) {
	deep[x] = d;
	if (node[x * 2] != -1)
		dfs(node[x * 2], d + 1);
	garo[x] = cnt++;
	if (node[x * 2 + 1] != -1)
		dfs(node[x * 2 + 1], d + 1);
}

int main() {
	memset(low, 40, sizeof(low));
	memset(big, 0xff, sizeof(big));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		node[a * 2] = b;
		node[a * 2 + 1] = c;
		chk[b] = chk[c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i])
			dfs(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (low[deep[i]] > garo[i])
			low[deep[i]] = garo[i];
		if (big[deep[i]] < garo[i])
			big[deep[i]] = garo[i];
	}
	int maxi = -1;
	int myi = 0;
	for (int i = 1; i <= 10000; i++) {
		if (maxi < big[i] - low[i] + 1) {
			maxi = big[i] - low[i] + 1;
			myi = i;
		}
	}
	printf("%d %d\n", myi, maxi);
	return 0;
}