#include<stdio.h>
#include<vector>
#include<memory.h>
#include<queue>
#include<algorithm>

struct pos {
	int a, b, c, d;
	bool operator<(const pos&io)const {
		if (a == io.a)return b < io.b;
		return a < io.a;
	}
};

int n, m;
std::vector<int>b[120];
std::vector<int>e[120];
pos inp[5051];
int bb[120][10010];
int ee[120][10010];
std::priority_queue<int>ans;

int main() {
	scanf("%d %d", &n, &m);
	b[1].push_back(0);
	e[1].push_back(0);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &inp[i].a, &inp[i].b, &inp[i].c, &inp[i].d);
	}
	std::sort(inp + 1, inp + 1 + m);
	for (int j = 1; j <= m; j++) {
		for (int k = 0; k < b[inp[j].a].size(); k++) {
			if (!bb[inp[j].b][inp[j].c + b[inp[j].a][k]]) {
				b[inp[j].b].push_back(inp[j].c + b[inp[j].a][k]);
				bb[inp[j].b][inp[j].c + b[inp[j].a][k]] = true;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int k = 0; k < e[inp[j].a].size(); k++) {
			if (!ee[inp[j].b][inp[j].d + e[inp[j].a][k]]) {
				e[inp[j].b].push_back(inp[j].d + e[inp[j].a][k]);
				ee[inp[j].b][inp[j].d + e[inp[j].a][k]] = true;
				if (inp[j].b == n&&bb[n][inp[j].d + e[inp[j].a][k]])
					ans.push(-inp[j].d - e[inp[j].a][k]);
			}
		}
	}
	if (ans.size())
		printf("%d\n", -ans.top());
	else
		printf("IMPOSSIBLE\n");
	return 0;
}