#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct pos {
	int val, idx;
	pos() {};
	pos(int a, int b) {
		val = a; idx = b;
	}
	bool operator<(const pos&io)const {
		if (val == io.val)return idx < io.idx;
		return val < io.val;
	}
};

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int>vec;
		queue<pos>q;
		int save;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			q.push(pos(a, i));
			vec.push_back(a);
			if (i == m)save = a;
		}
		sort(vec.begin(), vec.end(), cmp);
		int idx = 0;
		int day = 0;
		while (q.size()) {
			if (vec[idx] > q.front().val) {
				q.push(q.front()); q.pop();
			}
			else {
				if (q.front().idx == m)break;
				q.pop(); day++; idx++;
			}
		}
		printf("%d\n", day + 1);
	}
	return 0;
}