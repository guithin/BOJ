#include<bits/stdc++.h>
using namespace std;

struct pos {
	int sp, ep;
	pos() {};
	pos(int a, int b) {
		sp = a; ep = b;
	}
	bool operator<(const pos&io)const {
		return sp < io.sp;
	}
};

int n, m;
pos inp[5010];
vector<pos>vec;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &inp[i].sp, &inp[i].ep);
	}
	sort(inp + 1, inp + 1 + m);
	int s = inp[1].sp;
	int e = inp[1].ep;
	for (int i = 2; i <= m; i++) {
		if (e >= inp[i].sp) {
			e = max(inp[i].ep, e);
		}
		else {
			vec.push_back(pos(s, e));
			s = inp[i].sp;
			e = inp[i].ep;
		}
	}
	vec.push_back(pos(s, e));
	int ans = n;
	for (int i = 0; i < vec.size(); i++) {
		ans -= vec[i].ep - vec[i].sp;
	}
	printf("%d\n", ans);
	return 0;
}