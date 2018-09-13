#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

int match[10010]; //cow
int matched[10010]; //room
int n, m;

int visit[10010];
int chknum = 1;

vector<int>vec[210];

int dfs(int x) {
	if (visit[x] == chknum)return 0;
	visit[x] = chknum;
	for (int i = 0; i < vec[x].size(); i++) {
		if (matched[vec[x][i]] != -1) {
			int tmp = dfs(matched[vec[x][i]]);
			if (tmp == 1) {
				match[x] = vec[x][i];
				matched[vec[x][i]] = x;
				return 1;
			}
		}
		else {
			match[x] = vec[x][i];
			matched[vec[x][i]] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
	memset(match, 0xff, sizeof(match));
	memset(matched, 0xff, sizeof(matched));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			int temp;
			scanf("%d", &temp);
			vec[i].push_back(temp);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dfs(i);
		chknum++;
	}
	printf("%d\n", ans);
	return 0;
}