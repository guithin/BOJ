#include<stdio.h>
#include<vector>
using namespace std;
vector<int> vec[101];
bool check[101] = { 0 };
void dfs(int cur) {
	check[cur] = true;
	for (int i = 0; i < vec[cur].size(); i++) {
		int next = vec[cur][i];
		if (check[next] == true)
			continue;
		dfs(next);
	}
}



int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == true) cnt++;
	}
	printf("%d\n", cnt-1);
	return 0;
}