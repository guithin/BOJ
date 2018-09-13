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
int dist[20010];
int cnt[20010];
bool chk[20010];
vector<pos>vec[20010];
queue<int>q;

int main() {
	scanf("%d %d", &v, &e);
	int start;
	scanf("%d", &start);
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
	}
	memset(dist, 40, sizeof(dist));
	dist[start] = 0;
	q.push(start);
	while (q.size()) {
		int now = q.front(); q.pop();
		chk[now] = false;
		for (int i = 0; i < vec[now].size(); i++) {
			if (dist[vec[now][i].a] > dist[now] + vec[now][i].b) {
				dist[vec[now][i].a] = dist[now] + vec[now][i].b;
				if (!chk[vec[now][i].a]) {
					q.push(vec[now][i].a);
					chk[vec[now][i].a] = true;
				}
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[0] == dist[i]) {
			printf("INF\n");
		}
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}