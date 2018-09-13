#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>dp;
vector<int>inp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		inp.push_back(a);
	}
	dp.push_back(inp[0]);
	for (int i = 1; i < inp.size(); i++) {
		auto it = lower_bound(dp.begin(), dp.end(), inp[i]);
		if (it == dp.end())
			dp.push_back(inp[i]);
		else
			*it = inp[i];
	}
	cout << dp.size() << '\n';
	return 0;
}