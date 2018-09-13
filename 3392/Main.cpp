#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct pos {
	int x1, y1, x2, y2;
	pos() {};
	pos(int a, int b, int c, int d) {
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
	bool operator<(const pos&io)const {
		return x1 < io.x1;
	}
};

int n;
vector<pos>vec;
int how[30010];
int val[30010];

int main() {
    scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a++; b++; c++; d++;
		vec.push_back(pos(a, b, c, d));
	}
	sort(vec.begin(), vec.end());
	for (auto &it : vec) {
		for (int i = it.y1; i < it.y2; i++) {
			if (how[i] < it.x1) {
				how[i] = it.x2;
				val[i] += it.x2 - it.x1;
			}
			else if (how[i] < it.x2) {
				val[i] += it.x2 - how[i];
				how[i] = it.x2;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 30001; i++)
		ans += val[i];
	printf("%d\n", ans);
	return 0;
}