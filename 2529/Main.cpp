#include<stdio.h>
#include<vector>

std::vector<int>vec[15];
std::vector<int>vec2[15];
int n;
bool chk[15] = { 0 };
bool chk2[15] = { 0 };
int table[15] = { 0 };
int table2[15] = { 0 };
int tar[15] = { 0 };
int tar2[15] = { 0 };
int cnt;
int cnt2;
void dfs(int cur) {
	if (chk[cur])return;
	if (!tar[cur]) {
		table[cur] = cnt;
		chk[cur] = true;
		cnt--;
		for (int i = 0; i < vec[cur].size(); i++) {
			tar[vec[cur][i]]--;
			dfs(vec[cur][i]);
		}
	}
}

void dfs2(int cur) {
	if (chk2[cur])return;
	if (!tar2[cur]) {
		table2[cur] = cnt2;
		chk2[cur] = true;
		cnt2++;
		for (int i = 0; i < vec2[cur].size(); i++) {
			tar2[vec2[cur][i]]--;
			dfs2(vec2[cur][i]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char temp;
		scanf(" %c", &temp);
		if (temp == '<') {
			tar[i]++;
			tar2[i + 1]++;
			vec2[i].push_back(i + 1);
			vec[i + 1].push_back(i);
		}
		else {
			tar[i + 1]++;
			tar2[i]++;
			vec2[i + 1].push_back(i);
			vec[i].push_back(i + 1);
		}
	}
	cnt = 9;
	for (int i = 1; i <= n + 1; i++) {
		if (!tar[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		if (!tar2[i]) {
			dfs2(i);
		}
	}
	for (int i = 1; i <= n + 1; i++)printf("%d", table[i]);
	printf("\n");
	for (int i = 1; i <= n + 1; i++)printf("%d", table2[i]);
	printf("\n");
	return 0;
}