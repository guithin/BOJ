#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

pair<int, int>my[10];
pair<int, int>you[10];

int n, m;
bool pick[10];
bool modok;

int arr[10];
int atk[10];

bool chk() {
	bool chk[15] = {};
	int maxi = -1;
	for (int i = 1; i <= m; i++) {
		maxi = max(maxi, you[i].second);
		chk[you[i].second] = true;
	}
	for (int i = 1; i <= n; i++) {
		chk[my[i].second] = true;
	}
	for (int i = 1; i <= maxi; i++) {
		if (!chk[i])return false;
	}
	modok = true;
	return true;
}

bool back(int cur) {
	if (chk()) {
		return true;
	}
	if (cur == n + 1) {
		return false;
	}
	if (back(cur + 1))
		return true;
	for (int i = 1; i <= m; i++) {
		if (you[i].second <= 0)continue;
//		if (my[arr[cur]].first >= you[i].second && you[i].first >= my[arr[cur]].second)continue;
		atk[cur] = i;
		int q = my[arr[cur]].second;
		int w = you[i].second;
		my[arr[cur]].second = max(my[arr[cur]].second - you[i].first, 0);
		you[i].second = max(you[i].second - my[arr[cur]].first, 0);
		if (back(cur + 1))
			return true;
		my[arr[cur]].second = q;
		you[i].second = w;
		atk[cur] = 0;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &my[i].first, &my[i].second);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &you[i].first, &you[i].second);
	}
	if (!m) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	do {
		if (back(1)) {
			int cnt = 1;
			for (int i = 1; i <= n; i++) {
				if (atk[i])cnt++;
			}
			printf("%d\n", cnt);
			for (int i = 1; i <= n; i++) {
				if (atk[i])printf("attack %d %d\n", arr[i], atk[i]);
			}
			if (modok)printf("use modok\n");
			return 0;
		}
	} while (next_permutation(arr + 1, arr + 1 + n));
	printf("-1\n");
	return 0;
}