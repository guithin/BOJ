#include<bits/stdc++.h>
using namespace std;

vector<char>usechar;
bool chk[26];
int pick[26];
int used[10];
char str[11][10];
int ans = 0;
int n;

void back(int cur) {
	if (cur == usechar.size()) {
		int temp = 0;
		for (int i = 1; i <= n; i++) {
			int t = 0;
			for (int j = 0; str[i][j]; j++) {
				t *= 10; t += pick[str[i][j] - 'A'];
			}
			temp += t;
		}
		ans = max(ans, temp);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (used[i])continue;
		pick[usechar[cur]] = i;
		used[i] = 1;
		back(cur + 1);
		used[i] = 0;
		pick[usechar[cur]] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i]);
		for (int j = 0; str[i][j]; j++) {
			chk[str[i][j] - 'A'] = true;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (chk[i])usechar.push_back(i);
	}
	back(0);
	printf("%d\n", ans);
	return 0;
}