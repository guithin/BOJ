#include<stdio.h>
#include<vector>
#include<memory.h>

std::vector<int>vec[1010];
bool chk[1010] = { 0 };
bool check[1010] = { 0 };
bool flag = true;

void dfs(int cur) {
	if (check[cur]) {
		flag = false;
		return;
	}
	check[cur] = true;
	for (int i = 0; i < vec[cur].size(); i++) {
		dfs(vec[cur][i]);
	}
}

int main() {
	int test = 0;
	while (++test) {
		for (int i = 0; i <= 1000; i++)vec[i].clear();
		memset(chk, 0, sizeof(chk));
		memset(check, 0, sizeof(check));
		flag = true;
		while (1) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a == 0 && b == 0)break;
			if (a < 0 && b < 0)return 0;
			if (chk[b]) {
				flag = false;
			}
			chk[b] = true;
			vec[a].push_back(b);
		}
		int cnt = 0;
		for (int i = 0; i <= 1000; i++) {
			if (vec[i].size() > 0 && !chk[i]) {
				if (cnt) {
					flag = false;
					break;
				}
				cnt++;
				dfs(i);
			}
		}
		for (int i = 0; i <= 1000; i++) {
			if (!check[i] && chk[i]) {
				flag = false;
			}
		}
		printf("Case %d is%sa tree.\n", test, flag ? " " : " not ");
	}
	return 0;
}