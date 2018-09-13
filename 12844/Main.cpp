#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int high = 1;
int tree[2048586];
int lazy[2048586];
void lazyup(int node) {
	if (lazy[node]) {
		if (node >= high)
			tree[node] ^= lazy[node];
		else {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void lazyup(int node, int nl, int nr, int fl, int fr, int c) {
	lazyup(node);
	if (fl <= nl && nr <= fr) {//포함구간
		if (nl == nr)tree[node] ^= c;//리프노드이면 c를 xor
		else lazy[node] = c;
		return;
	}
	if (fr < nl || nr < fl)return;
	int mid = (nl + nr) / 2;
	lazyup(node * 2, nl, mid, fl, fr, c);
	lazyup(node * 2 + 1, mid + 1, nr, fl, fr, c);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int find(int node, int nl, int nr, int fl, int fr) {
	lazyup(node);
	if (fl <= nl && nr <= fr) return tree[node];//포함구간이면 그 값 return
	if (fr < nl || nr < fl)return 0;//벗어나면 0 retrun
	int mid = (nl + nr) / 2;
	return find(node * 2, nl, mid, fl, fr) ^ find(node * 2 + 1, mid + 1, nr, fl, fr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n > high)high <<= 1;
	for (int i = 0; i < n; i++) {
		cin >> tree[high + i];
	}
	//리프노드가 high(n보다 큰 2의 멱수)개인 트리
	//리프노드는 high~high+n-1까지

	for (int i = high - 1; i >= 1; i--)
		tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
	//init update

	cin >> m;
	while (m--) {
		int mode;
		cin >> mode;
		if (mode == 1) {
			int a, b, c;
			cin >> a >> b >> c;
			a++; b++;
			if (a > b)swap(a, b);
			lazyup(1, 1, high, a, b, c);
		}
		else {
			int a, b;
			cin >> a >> b;
			a++; b++;
			if (a > b)swap(a, b);
			cout << find(1, 1, high, a, b) << '\n';
		}
	}
	return 0;
}