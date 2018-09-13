#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>

int b, e, p, n, m;
std::vector<int>vec[40010];
std::queue<int>q;
int db[40010] = { 0 };
int de[40010] = { 0 };
int dp[40010] = { 0 };

int main() {
	scanf("%d %d %d %d %d", &b, &e, &p, &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	memset(db, 40, sizeof(db));
	memset(de, 40, sizeof(de));
	memset(dp, 40, sizeof(dp));
	db[1] = 0;
	q.push(1);
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			if (db[vec[now][i]] > db[now] + b) {
				db[vec[now][i]] = db[now] + b;
				q.push(vec[now][i]);
			}
		}
	}
	de[2] = 0;
	q.push(2);
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			if (de[vec[now][i]] > de[now] + e) {
				de[vec[now][i]] = de[now] + e;
				q.push(vec[now][i]);
			}
		}
	}
	dp[n] = 0;
	q.push(n);
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			if (dp[vec[now][i]] > dp[now] + p) {
				dp[vec[now][i]] = dp[now] + p;
				q.push(vec[now][i]);
			}
		}
	}
	int mini = 1234567890;
	int myi = 0;
	for (int i = 1; i <= n; i++) {
		if (mini > de[i] + db[i] + dp[i]) {
			mini = de[i] + db[i] + dp[i];
			myi = i;
		}
	}
	printf("%d\n", mini);
	return 0;
}