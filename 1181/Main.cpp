#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string inp[200010];

bool cmp(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inp[i];
	}
	sort(inp + 1, inp + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		if (inp[i] == inp[i + 1])continue;
		cout << inp[i] << '\n';
	}
	return 0;
}