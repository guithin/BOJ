#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

const int number = 200010;

struct pos {
	int x1, y1, x2, y2;
	int idx;
	pos() {};
	pos(int a, int b, int c, int d) {
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
	bool operator<(const pos&io)const {
		return x1 < io.x1;
	}
};

int n;
int high = 1;
vector<pos>vec;
vector<int>srtx;
vector<int>srty;
vector<int>dp;
priority_queue<pos>q;
int inp[100010];
int tree[1524298];

bool cmpx(pos a, pos b) {
	if (a.x2 == b.x2)
		return a.y2 > b.y2;
	return a.x2 > b.x2;
}

void pp(int num, int c) {
	for (int i = high + num - 1; i >= 1; i >>= 1) {
		tree[i] = max(tree[i], c);
	}
}

int find(int node, int nl, int nr, int fl) {
	if (fl < nl)return tree[node];
	if (nr <= fl)return 0;
	int mid = (nl + nr) / 2;
	return max(find(node * 2, nl, mid, fl), find(node * 2 + 1, mid + 1, nr, fl));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	while (number > high)high <<= 1;

	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vec.push_back(pos(a, b, c, d));
		srtx.push_back(a); srtx.push_back(c);
		srty.push_back(b); srty.push_back(d);
	}

	sort(srtx.begin(), srtx.end());
	sort(srty.begin(), srty.end());
	srtx.resize(unique(srtx.begin(), srtx.end()) - srtx.begin());
	srty.resize(unique(srty.begin(), srty.end()) - srty.begin());
	for (auto &it : vec) {
		it.x1 = lower_bound(srtx.begin(), srtx.end(), it.x1) - srtx.begin() + 1;
		it.x2 = lower_bound(srtx.begin(), srtx.end(), it.x2) - srtx.begin() + 1;
		it.y1 = lower_bound(srty.begin(), srty.end(), it.y1) - srty.begin() + 1;
		it.y2 = lower_bound(srty.begin(), srty.end(), it.y2) - srty.begin() + 1;
	}

	sort(vec.begin(), vec.end(), cmpx);
	for (int i = 0; i < vec.size(); i++)
		vec[i].idx = i;
	for (int i = 0; i < vec.size(); i++) {
		while (1) {
			if (q.size() && q.top().x1 > vec[i].x2) {
				pp(q.top().y1, inp[q.top().idx]);
				q.pop();
			}
			else break;
		}
		inp[i] = max(inp[i], find(1, 1, high, vec[i].y2)) + 1;
		q.push(vec[i]);
	}
	int maxi = -1;
	for (int i = 0; i <= n; i++)
		if (maxi < inp[i])maxi = inp[i];
	cout << maxi << '\n';
	return 0;
}