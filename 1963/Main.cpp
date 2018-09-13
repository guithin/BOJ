#include<bits/stdc++.h>
using namespace std;

int su[10010];
vector<int>vec;
vector<int>pat[1100];

int diff(int a, int b) {
	int ret = 0;
	while (a) {
		ret += (a % 10) != (b % 10);
		a /= 10; b /= 10;
	}
	return ret;
}

int main() {
	su[0] = su[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if (su[i])continue;
		if (i >= 1000)vec.push_back(i);
		for (int j = 2; j*i <= 10000; j++) {
			su[i*j] = 1;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (diff(vec[i], vec[j]) == 1) {
				pat[i].push_back(j);
				pat[j].push_back(i);
			}
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
		b = lower_bound(vec.begin(), vec.end(), b) - vec.begin();
		int c[1100];
		memset(c, 40, sizeof(c));
		queue<int>q;
		q.push(a);
		c[a] = 0;
		bool flag = false;
		while (q.size()) {
			int now = q.front(); q.pop();
			for (int i = 0; i < pat[now].size(); i++) {
				if (c[pat[now][i]] != c[1099])continue;
				c[pat[now][i]] = c[now] + 1;
				q.push(pat[now][i]);
			}
			if (c[b] != c[1099]) {
				printf("%d\n", c[b]);
				flag = true;
				break;
			}
		}
		if (!flag)printf("Impossible\n");
	}
	return 0;
}