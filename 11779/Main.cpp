#include<stdio.h>
#include<queue>
#include<vector>
int inf = 987654321;

struct pos {
	int to;
	int w;
};

struct in {
	int co;
	int num;
	bool operator <(const in&io)const {
		return co > io.co;
	}
};

std::vector <pos> edge[1010];
std::priority_queue <in> costq;
int path[1010] = { 0 };
int cost[1010] = { 0 };
bool check[1010] = { 0 };
int ans[1000] = { 0 };
int idx = 0;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pos input;
		input.to = b;
		input.w = c;
		edge[a].push_back(input);
	}
	int start, end;
	scanf("%d %d", &start, &end);
	for (int i = 1; i <= n; i++) {
		cost[i] = inf;
		in temp;
		if (i == start)temp.co = 0;
		else temp.co = inf;
		temp.num = i;
		costq.push(temp);
	}
	cost[start] = 0;
	for (int i = 1; i <= n; i++) {
		int k = costq.top().num;
		int now = costq.top().co;
		check[k] = true;
		costq.pop();
		for (int j = 0; j < edge[k].size(); j++) {
			if (now + edge[k][j].w < cost[edge[k][j].to]) {
				in inp;
				inp.num = edge[k][j].to;
				inp.co = now + edge[k][j].w;
				cost[edge[k][j].to] = now + edge[k][j].w;
				costq.push(inp);
				path[edge[k][j].to] = k;
			}
		}
	}
	printf("%d\n", cost[end]);
	int cu = end;
	ans[idx] = end;
	idx++;
	while (cu != start) {
		ans[idx] = path[cu];
		cu = path[cu];
		idx++;
	}
	printf("%d\n", idx);
	for (int i = idx - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}