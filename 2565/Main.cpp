#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<limits.h>
using namespace std;

struct pos {
	int a, b, idx;
	pos() {};
	pos(int _a, int _b, int c) {
		a = _a; b = _b; idx = c;
	}
	bool operator<(const pos&io)const {
		return a < io.a;
	}
};

vector<pos>vec;
vector<int>dp;
vector<int>ans;
int save[100010];
bool chk[100010];

bool cmp(pos &a, pos &b) {
	return a.idx < b.idx;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back(pos(a, b, i));
	}
//	sort(vec.begin(), vec.end(), cmp);
/*	for (int i = 0; i < vec.size(); i++) {
		vec[i].b = i + 1;
	}
*/
	sort(vec.begin(), vec.end());
/*	for (int i = 0; i < vec.size(); i++) {
		vec[i].a = i + 1;
	}*/
	int ed = 0;
	for (int i = 0; i < vec.size(); i++) {
		auto it = lower_bound(dp.begin(), dp.end(), vec[i].b);
		if (it == dp.end()) {
			if (!i)save[i] = -1;
			else save[i] = dp[it - dp.begin() - 1];
			dp.push_back(vec[i].b);
			ed = i;
		}
		else {
			if (it == dp.begin()) {
				save[i] = -1;
			}
			else {
				save[i] = dp[it - dp.begin() - 1];
			}
			*it = vec[i].b;
		}
	}
	printf("%d\n", n - dp.size());
	return 0;
}