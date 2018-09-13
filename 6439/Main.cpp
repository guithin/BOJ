#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

struct dot {
	ll x, y;
	dot() {};
	dot(ll a, ll b) {
		x = a; y = b;
	}
	bool operator==(const dot&io) {
		return x == io.x&&y == io.y;
	}
};

struct seg {
	dot left, right;
	seg() {};;
	seg(dot a, dot b) {
		left = a; right = b;
	}
};

ll ccw(dot a, seg b) {
	ll chk = (b.right.x*b.left.y + b.left.x*a.y + a.x*b.right.y) - (b.right.x*a.y + b.left.x*b.right.y + a.x*b.left.y);
	if (!chk)return 0;
	if (chk < 0)return -1;
	if (chk > 0)return 1;
}

ll ccw(seg a, seg b) {
	ll temp;
	temp = ccw(a.left, b)*ccw(a.right, b);
	if (temp > 0)return 0;
	temp = ccw(b.left, a)*ccw(b.right, a);
	if (temp > 0)return 0;
	return 1;
}

bool box(seg a, seg b) {
	ll temp;
	if (a.left.x > a.right.x)swap(a.left.x, a.right.x);
	if (a.left.y > a.right.y)swap(a.left.y, a.right.y);
	if (b.left.x > b.right.x)swap(b.left.x, b.right.x);
	if (b.left.y > b.right.y)swap(b.left.y, b.right.y);
	temp = (a.right.x - b.left.x)*(a.left.x - b.right.x);
	if (temp > 0)return false;
	temp = (a.right.y - b.left.y)*(a.left.y - b.right.y);
	if (temp > 0)return false;
	return true;
}

bool include(seg a, seg b) {
	if (b.left.x > b.right.x)
		swap(b.left.x, b.right.x);
	if (b.left.y > b.right.y)
		swap(b.left.y, b.right.y);
	ll xs[5] = { a.left.x, a.right.x, b.left.x, b.right.x };
	ll ys[5] = { a.left.y, a.right.y, b.left.y, b.right.y };
	sort(xs, xs + 4); sort(ys, ys + 4);
	if (dot(xs[1], ys[1]) == b.left&&dot(xs[2], ys[2]) == b.right)return true;
	return false;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		seg temp;
		cin >> temp.left.x >> temp.left.y >> temp.right.x >> temp.right.y;
		dot inp[5];
		for (ll i = 1; i <= 3; i += 2) {
			cin >> inp[i].x >> inp[i].y;
		}
		inp[2].x = inp[3].x; inp[2].y = inp[1].y;
		inp[4].x = inp[1].x; inp[4].y = inp[3].y;
		bool flag = false;
		for (ll i = 1; i <= 4; i++) {
			int nex = i + 1;
			if (nex == 5)nex = 1;
			if (!box(seg(inp[i], inp[nex]), temp))continue;
			if (ccw(seg(inp[i], inp[nex]), temp)) {
				cout << "T\n";
//				cout << i << ", 1\n";
				flag = true;
				break;
			}
//			cout << i << ", 0\n";
			if (flag)break;
		}
		if (!flag) {
			if (include(seg(inp[1], inp[3]), temp))
				cout << "T\n";
			else
				cout << "F\n";
		}
	}
	return 0;
}