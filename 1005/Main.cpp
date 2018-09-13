#include<stdio.h>
#include<vector>
#include<memory.h>
#include<algorithm>
int inp[1010];
std::vector<int>vec[1010];
int tar[1010];
int ans[1010];

int back(int cur) {
	if (ans[cur] != -1)return ans[cur];
	int maxi = 0;
	for (int i = 0; i < vec[cur].size(); i++) {
		int temp = back(vec[cur][i]);
		if (temp > maxi)maxi = temp;
	}
	return ans[cur] = maxi + inp[cur];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(inp, 0, sizeof(inp));
		memset(tar, 0, sizeof(tar));
		memset(ans, 0xff, sizeof(ans));
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			vec[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", inp + i);
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vec[b].push_back(a);
			tar[a]++;
		}
		int start;
		scanf("%d", &start);
		printf("%d\n", back(start));
	}
	return 0;
}