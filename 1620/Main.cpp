#include<bits/stdc++.h>
using namespace std;

struct pos {
	string str;
	int idx;
	pos(char *p, int idx) {
		str = string(p);
		this->idx = idx;
	}
	bool operator<(const pos& io) {
		return str < io.str;
	}
	bool operator==(const pos& io) {
		return str == io.str;
	}
};

vector<pos>vec;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int alloc = 1;
	for (int i = 1; i <= n; i++) {
		char buf[100]; scanf("%s", buf);
		vec.push_back(pos(buf, alloc++));
	}
	vector<pos>vec2 = vec;
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= m; i++) {
		char buf[100]; scanf("%s", buf);
		if (buf[0] >= '0'&&buf[0] <= '9') {
			int k; sscanf(buf, "%d", &k);
			printf("%s\n", vec2[k - 1].str.c_str());
		}
		else {
			int l = 0, r = vec.size();
			int k = lower_bound(vec.begin(), vec.end(), pos(buf, 0)) - vec.begin();
			printf("%d\n", vec[k].idx);
		}
	}
	return 0;
}