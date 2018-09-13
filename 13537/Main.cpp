#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int>srt;
vector<int>vec;
struct pos {
	int a, b, c, idx, ans;
	pos() {};
	pos(int q, int w, int e) {
		a = q; b = w; c = e;
	}
	bool operator<(const pos&io)const {
		return c > io.c;
	}
};

struct ffff {
	int val, idx;
	ffff() {};
	ffff(int a, int b) {
		val = a; idx = b;
	}
	bool operator<(const ffff&io)const {
		return val > io.val;
	}
};

vector<pos>cur;
int high = 1;
ffff idx[100010];
int tree[800010];

bool cmp(pos a, pos b) {
	return a.idx < b.idx;
}

int find(int node, int nl, int nr, int fl, int fr) {
	if (fl <= nl && nr <= fr)return tree[node];
	if (nr < fl || fr < nl)return 0;
	int mid = (nl + nr) / 2;
	return find(node * 2, nl, mid, fl, fr) + find(node * 2 + 1, mid + 1, nr, fl, fr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	while (high < 200010)high <<= 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
		srt.push_back(a);
		idx[i].val = a;
		idx[i].idx = i;
	}

	int m;
	cin >> m;

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cur.push_back(pos(a, b, c));
		cur[i - 1].idx = i - 1;
		srt.push_back(c);
	}

	sort(srt.begin(), srt.end());

	srt.resize(unique(srt.begin(), srt.end()) - srt.begin());

	for (int i = 0; i < n; i++)
		idx[i].val = lower_bound(srt.begin(), srt.end(), idx[i].val) - srt.begin() + 1;

	sort(idx, idx + n);

	for (auto &it : vec) {
		it = lower_bound(srt.begin(), srt.end(), it) - srt.begin() + 1;
	}
	for (auto &it : cur) {
		it.c = lower_bound(srt.begin(), srt.end(), it.c) - srt.begin() + 1;
	}
//
	sort(cur.begin(), cur.end());

	int point = 0;

	for (int i = 0; i < cur.size(); i++) {
		while (point < vec.size() && vec[idx[point].idx] > cur[i].c) {
			for (int j = high + idx[point].idx; j >= 1; j >>= 1) {
				tree[j]++;
			}
			point++;
		}
		cur[i].ans = find(1, 1, high, cur[i].a, cur[i].b);
	}
	sort(cur.begin(), cur.end(), cmp);
	for (auto &it : cur)
		cout << it.ans << '\n';
	return 0;
}