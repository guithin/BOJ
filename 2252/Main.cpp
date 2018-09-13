#include<stdio.h>
#include<queue>
#include<vector>

int in[33000];
std::queue <int> q;
std::vector <int> vec[33000];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		in[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < vec[now].size(); i++) {
			in[vec[now][i]]--;
			if (in[vec[now][i]] == 0)q.push(vec[now][i]);
		}
	}
	printf("\n");
	return 0;
}