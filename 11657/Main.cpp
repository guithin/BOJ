#include<stdio.h>
#include<memory.h>
#include<queue>
#include<vector>
using namespace std;

struct pos {
	int a, b;
	pos() {};
	pos(int a, int b) {
		this->a = a;
		this->b = b;
	}
};

int v, e;
int dist[510];
int cnt[510];
bool chk[510];
vector<pos>vec[510];
queue<int>q;

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
	}
	memset(dist, 40, sizeof(dist));
	dist[1] = 0;
	q.push(1);
	while (q.size()) {
		int now = q.front(); q.pop();
		chk[now] = false;
		for (int i = 0; i < vec[now].size(); i++) {
			if (dist[vec[now][i].a] > dist[now] + vec[now][i].b) {
				dist[vec[now][i].a] = dist[now] + vec[now][i].b;
				if (!chk[vec[now][i].a]) {
					q.push(vec[now][i].a);
					chk[vec[now][i].a] = true;
					cnt[vec[now][i].a]++;
					if (cnt[vec[now][i].a] > v) {
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= v; i++) {
		if (dist[0] == dist[i]) {
			printf("-1\n");
		}
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}