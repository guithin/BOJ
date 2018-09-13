#include<stdio.h>
#include<vector>
#include<queue>

struct pos {
	int to, cost;
	pos() {};
	pos(int a, int b) {
		to = a;
		cost = b;
	}
};

std::vector <pos> vec[10010];
int n;
int node_max1[10010] = { 0 };
int node_max2[10010] = { 0 };
int max = -99999;

int div(int cur) {
	if (node_max1[cur] != 0)return node_max1[cur];
	if (vec[cur].size() == 0) {
		return 0;
	}
	std::priority_queue<int>q;
	for (int i = 0; i < vec[cur].size(); i++) {
		q.push(div(vec[cur][i].to) + vec[cur][i].cost);
	}
	if (q.size() >= 2) {
		node_max1[cur] = q.top();
		q.pop();
		node_max2[cur] = q.top();
		if (node_max1[cur] + node_max2[cur] > max) {
			max = node_max1[cur] + node_max2[cur];
		}
	}
	else {
		node_max1[cur] = q.top();
	}
	return node_max1[cur];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
	}
	div(1);
	for (int i = 1; i <= n; i++) {
		if (node_max1[i] + node_max2[i] > max) {
			max = node_max1[i] + node_max2[i];
		}
	}
	printf("%d\n", max);
	return 0;
}