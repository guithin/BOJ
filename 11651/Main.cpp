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
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	});
	for (pos i : vec) {
		printf("%d %d\n", i.x, i.y);
	}
	return 0;
}