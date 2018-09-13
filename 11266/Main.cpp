#include<stdio.h>
#include<vector>
#include<algorithm>

int v, e;
std::vector<int>vec[10010];
std::vector<int>node;
int vst[10010] = { 0 };
int vst2[10010] = { 0 };
int chk[10010] = { 0 };
int chk2[10010] = { 0 };
int cnt = 0;
int cnt2 = 0;
int ans = 0;
std::vector<int>ffff;

int dfs(int x) {
	if (vst[x])return vst[x];
	vst[x] = ++cnt;
	int mini = 987654321;
	for (int i = 0; i < vec[x].size(); i++) {
		int temp = dfs(vec[x][i]);
		if (temp == vst[x]) {
			chk[x] = 1;
		}
		if (temp < mini)
			mini = temp;
	}
	return mini;
}

int dfs2(int x) {
	if (vst2[x])return vst2[x];
	vst2[x] = ++cnt2;
	int mini = 987654231;
	for (int i = 0; i < vec[x].size(); i++) {
		int temp = dfs2(vec[x][i]);
		if (temp == vst2[x]) {
			chk2[x] = 1;
		}
		if (temp < mini)
			mini = temp;
	}
	return mini;
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!vst[i]) {
			dfs(i);
			if (vec[i].size())
				dfs2(vec[i][0]);
		}
	}
	for (int i = 1; i <= v; i++) {
		if (chk[i] && chk2[i])ffff.push_back(i);
	}
	printf("%d\n", ffff.size());
	for (int i = 0; i < ffff.size(); i++) {
		printf("%d ", ffff[i]);
	}
	printf("\n");
	return 0;
}