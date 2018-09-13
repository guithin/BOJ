#include<stdio.h>
#include<vector>
#include<memory.h>
#include<queue>
#include<algorithm>

struct pos {
	int a, b, c, d;
};

int n, m;
std::vector<int>b[20];
std::vector<int>e[20];
pos inp[150];
int bb[20][20000];
int ee[20][20000];

int main() {
	scanf("%d %d", &n, &m);
	b[1].push_back(0);
	e[1].push_back(0);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &inp[i].a, &inp[i].b, &inp[i].c, &inp[i].d);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < b[inp[j].a].size(); k++) {
				if (!bb[inp[j].b][inp[j].c + b[inp[j].a][k]]) {
					b[inp[j].b].push_back(inp[j].c + b[inp[j].a][k]);
					bb[inp[j].b][inp[j].c + b[inp[j].a][k]] = true;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < e[inp[j].a].size(); k++) {
				if (!ee[inp[j].b][inp[j].d + e[inp[j].a][k]]) {
					e[inp[j].b].push_back(inp[j].d + e[inp[j].a][k]);
					ee[inp[j].b][inp[j].d + e[inp[j].a][k]] = true;
				}
			}
		}
	}
	std::sort(b[n].begin(), b[n].end());
	std::sort(e[n].begin(), e[n].end());
	int bi = 0;
	int ei = 0;
	while (1) {
		if (bi==b[n].size() || ei==e[n].size()) {
			printf("IMPOSSIBLE");
			return 0;
		}
		if (b[n][bi] == e[n][ei]) {
			printf("%d\n", b[n][bi]);
			break;
		}
		else if (b[n][bi] < e[n][ei])bi++;
		else if (b[n][bi] > e[n][ei])ei++;
	}

	return 0;
}