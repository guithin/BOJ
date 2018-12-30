#include<bits/stdc++.h>
using namespace std;

struct pos {
	int day, delta;
	char cow;
	pos() {};
	pos(int a, char b, int c) {
		day = a; cow = b; delta = c;
	}
	bool operator<(const pos& io)const {
		return day < io.day;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	int val[4] = { 7, 7, 7, 7 };
	vector<pos>vec;
	for (int i = 1; i <= n; i++) {
		int a, b; char c[100];
		scanf("%d %s %d", &a, c, &b);
		vec.push_back(pos(a, c[0], b));
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	int status = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].cow == 'M') {
			val[1] += vec[i].delta;
		}
		else if (vec[i].cow == 'E') {
			val[2] += vec[i].delta;
		}
		else {
			val[3] += vec[i].delta;
		}
		int temp;
		if (val[1] == val[2] && val[2] == val[3])temp = 0;
		else if (val[1] == val[2] && val[2] > val[3])temp = 1;
		else if (val[2] == val[3] && val[3] > val[1])temp = 2;
		else if (val[1] == val[3] && val[3] > val[2])temp = 3;
		else if (val[1] > val[2] && val[1] > val[3])temp = 4;
		else if (val[2] > val[1] && val[2] > val[3])temp = 5;
		else if (val[3] > val[1] && val[3] > val[2])temp = 6;
		ans += status != temp;
		status = temp;
	}
	printf("%d\n", ans);
	return 0;
}