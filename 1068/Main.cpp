#include<stdio.h>
#include<vector>

int input[60] = { 0 };
std::vector <int> vec[60];
int e;
int ans = 0;
std::vector<int>s;

void back(int cur) {
	if (cur == e)return;
	if (vec[cur].size() == 0) {
		ans++;
		return;
	}
	for (int i = 0; i < vec[cur].size(); i++) {
		if (vec[cur][i] == e&&vec[cur].size() == 1)ans++;
		back(vec[cur][i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int start = 1;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == -1) {
			s.push_back(i);
		}
		else {
			vec[temp].push_back(i);
		}
	}
	scanf("%d", &e);
	for (int i = 0; i < s.size(); i++) {
		back(s[i]);
	}
	printf("%d\n", ans);
	return 0;
}