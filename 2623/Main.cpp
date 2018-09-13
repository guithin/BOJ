#include<stdio.h>
#include<vector>
struct pos {
	std::vector<int>vec[1010];
	int tar[1010] = { 0 };
	bool chk[1010] = { 0 };
	std::vector<int>stack;

	void dfs(int cur) {
		for (int i = 0; i < vec[cur].size(); i++) {
			if (!chk[vec[cur][i]]) {
				chk[vec[cur][i]] = true;
				dfs(vec[cur][i]);
			}
			else {
				bool flag = false;
				for (int j = 0; j < stack.size(); j++) {
					if (stack[j] == vec[cur][i]) {
						flag = true;
						break;
					}
				}
				if (!flag)chk[0] = false;
			}
		}
		stack.push_back(cur);
	}

	int main() {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int ii;
			scanf("%d", &ii);
			int ed, temp;
			scanf("%d", &ed);
			for (int i = 1; i < ii; i++) {
				scanf("%d", &temp);
				tar[ed]++;
				vec[temp].push_back(ed);
				ed = temp;
			}
		}
		chk[0] = true;
		for (int i = 1; i <= n; i++) {
			if (!tar[i]) {
				chk[i] = true;
				dfs(i);
			}
		}
		for (int i = 0; i <= n; i++) {
			if (!chk[i]) {
				printf("0\n");
				return 0;
			}
		}
		for (int i = 0; i < stack.size(); i++)printf("%d\n", stack[i]);
		return 0;
	}
};
int main() {
	pos func;
	func.main();
	return 0;
}