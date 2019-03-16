#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct pos {
	int x, y;
	pos() {}
	pos(int a, int b) {
		x = a; y = b;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<pos>vec;
	while (n--) {
		int a, b; scanf("%d %d", &a, &b);
		vec.push_back(pos(a, b));
	}
	sort(vec.begin(), vec.end(), [](pos &a, pos &b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});
	for (pos i : vec) {
		printf("%d %d\n", i.x, i.y);
	}
	return 0;
}