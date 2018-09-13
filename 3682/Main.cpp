#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include<memory.h>

struct pos {
	int n, m;
	std::vector<int> vec[20010];
	std::vector< std::vector<int> > scc;
	std::vector<int> tree[20010];
	std::stack<int> stk;
	int low[20010];
	int dep[20010];
	int chk[20010];
	int sci[20010];
	int ind[20010];
	int oud[20010];
	int cnt;
	int leaf;
	int root;
	pos() {
		memset(low, 0, sizeof(low));
		memset(dep, 0, sizeof(dep));
		memset(chk, 0, sizeof(chk));
		memset(sci, 0, sizeof(sci));
		memset(ind, 0, sizeof(ind));
		memset(oud, 0, sizeof(oud));
		cnt = 0;
		root = 0;
		leaf = 0;
	}

	void dfs(int x)
	{
		low[x] = dep[x] = ++cnt;
		chk[x] = true;
		stk.push(x);
		for (int i = 0; i < vec[x].size(); i++)
		{
			if (!dep[vec[x][i]])
			{
				dfs(vec[x][i]);
				low[x] = std::min(low[x], low[vec[x][i]]);
			}
			else if (chk[vec[x][i]])
			{
				low[x] = std::min(low[x], low[vec[x][i]]);
			}
		}
		if (low[x] == dep[x])
		{
			std::vector<int> temp;
			while (1)
			{
				int top = stk.top();
				stk.pop();
				chk[top] = false;
				temp.push_back(top);
				sci[top] = scc.size() + 1;
				if (low[top] == dep[top])
					break;
			}
			scc.push_back(temp);
		}
	}

	void dfs2(int x) {
		if (!tree[x].size()) {
			leaf++;
			return;
		}
		for (int i = 0; i<tree[x].size(); i++) {
			dfs2(tree[x][i]);
		}
	}

	int main()
	{
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!dep[i])
				dfs(i);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				if (sci[i] != sci[vec[i][j]])
				{
					tree[sci[i]].push_back(sci[vec[i][j]]);
					ind[sci[vec[i][j]]]++;
					oud[sci[i]]++;
				}
			}
		}
		for (int i = 1; i <= scc.size(); i++) {
			if (!ind[i])root++;
			if (!oud[i])leaf++;
		}
		if (root == 1 && leaf == 1) {
			printf("0\n");
			return 0;
		}
		printf("%d\n", root>leaf ? root : leaf);
		return 0;
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		pos temp;
		temp.main();
	}
	return 0;
}