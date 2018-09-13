#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

const int inf = 1234567890;
int n;
int inp[3][500010];
int lank[3][500010];
int tree[2000000];
bool chk[500010];
int high = 1;

int find(int node, int nl, int nr, int fl) {
	if (nr <= fl)return tree[node];
	if (fl < nl)return inf;
	int mid = (nl + nr) / 2;
	return min(find(node * 2, nl, mid, fl), find(node * 2 + 1, mid + 1, nr, fl));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(tree, 40, sizeof(tree));
	cin >> n;
	while (high < n)high <<= 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> inp[i][j];
			lank[i][inp[i][j]] = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (find(1, 1, high, lank[1][inp[0][i]]) > lank[2][inp[0][i]])
			chk[inp[0][i]] = 1;
		for (int j = high + lank[1][inp[0][i]] - 1; j >= 1; j >>= 1) {
			tree[j] = min(tree[j], lank[2][inp[0][i]]);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) {
			cnt++;
//			cout << i << '\n';
		}
	}
	cout << cnt << '\n';
	return 0;
}