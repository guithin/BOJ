#include<bits/stdc++.h>
using namespace std;

const int inf = 0x39393939;

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a; y = b;
	}
};

struct ship {
	pos s, e;
	int w;
};

int n, m, k, l, high1 = 1, high2 = 1;
ship inp[100010];
pos inpl[100010];
int cntl[100010];
vector<int>srtx;
vector<int>srty;
int tree1[1100000];
int tree2[1100000];

int searchTree(int *tree, int node, int nl, int nr, int fl, int fr) {
	if (fl <= nl && nr <= fr)return tree[node];
	if (nr < fl || fr < nl)return inf;
	int mid = (nl + nr) / 2;
	return min(searchTree(tree, node * 2, nl, mid, fl, fr), searchTree(tree, node * 2 + 1, mid + 1, nr, fl, fr));
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {//case start
		{//init, clear
			srtx.clear(); srty.clear();
			high1 = 1; high2 = 1;
			memset(tree1, 60, sizeof(tree1));
			memset(tree2, 60, sizeof(tree2));
			memset(cntl, 0, sizeof(cntl));
			memset(inpl, 0, sizeof(inpl));
		}

		{//input
			scanf("%d %d %d", &n, &k, &l);
			for (int i = 1; i <= k; i++) {
				scanf("%d %d %d %d %d", &inp[i].s.x, &inp[i].s.y, &inp[i].e.x, &inp[i].e.y, &inp[i].w);
				if (inp[i].s.x > inp[i].e.x)swap(inp[i].s.x, inp[i].e.x);
				if (inp[i].s.y > inp[i].e.y)swap(inp[i].s.y, inp[i].e.y);
				srtx.push_back(inp[i].s.x);
				srty.push_back(inp[i].s.y);
				srtx.push_back(inp[i].e.x);
				srty.push_back(inp[i].e.y);
			}
			for (int i = 1; i <= l; i++) {
				int a, b; scanf("%d %d", &a, &b);
				if (b) {
					inpl[i].x = a;
					srtx.push_back(a);
				}
				else {
					inpl[i].y = a;
					srty.push_back(a);
				}
			}
		}

		{//coordinate short
			sort(srtx.begin(), srtx.end()); srtx.resize(unique(srtx.begin(), srtx.end()) - srtx.begin());
			sort(srty.begin(), srty.end()); srty.resize(unique(srty.begin(), srty.end()) - srty.begin());
			for (int i = 1; i <= k; i++) {
				inp[i].s.x = lower_bound(srtx.begin(), srtx.end(), inp[i].s.x) - srtx.begin() + 1;
				inp[i].s.y = lower_bound(srty.begin(), srty.end(), inp[i].s.y) - srty.begin() + 1;
				inp[i].e.x = lower_bound(srtx.begin(), srtx.end(), inp[i].e.x) - srtx.begin() + 1;
				inp[i].e.y = lower_bound(srty.begin(), srty.end(), inp[i].e.y) - srty.begin() + 1;
			}
			for (int i = 1; i <= l; i++) {
				if (inpl[i].x) {
					inpl[i].x = lower_bound(srtx.begin(), srtx.end(), inpl[i].x) - srtx.begin() + 1;
				}
				else {
					inpl[i].y = lower_bound(srty.begin(), srty.end(), inpl[i].y) - srty.begin() + 1;
				}
			}
			n = srtx.size();
			m = srty.size();
		}

		{//tree setting
			while (high1 < n)high1 <<= 1;
			while (high2 < m)high2 <<= 1;
			for (int i = 1; i <= l; i++) {
				if (inpl[i].x) {
					tree1[high1 + inpl[i].x - 1] = min(i, tree1[high1 + inpl[i].x - 1]);
				}
				else {
					tree2[high2 + inpl[i].y - 1] = min(i, tree2[high2 + inpl[i].y - 1]);
				}
			}
			for (int i = high1 - 1; i; i--) {
				tree1[i] = min(tree1[i * 2], tree1[i * 2 + 1]);
			}
			for (int i = high2 - 1; i; i--) {
				tree2[i] = min(tree2[i * 2], tree2[i * 2 + 1]);
			}
		}

		{//find
			for (int i = 1; i <= k; i++) {
				int X = searchTree(tree1, 1, 1, high1, inp[i].s.x, inp[i].e.x);
				int Y = searchTree(tree2, 1, 1, high2, inp[i].s.y, inp[i].e.y);
				int temp = min(X, Y);
				if (temp <= l) {
					cntl[temp] = max(cntl[temp], inp[i].w);
				}
			}
		}

		{//print ans
			for (int i = 1; i <= l; i++) {
				printf("%d\n", cntl[i]);
			}
		}
	}
	return 0;
}