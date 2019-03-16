#include<bits/stdc++.h>
using namespace std;

char arr[5][10];
int top[5];

int r(int t) {
	return (t + 2) % 8;
}
int l(int t) {
	return (t + 6) % 8;
}

void change(int i, int ccw, int from) {
	if (i > 4 || i < 1)return;
	if (from != 1 && i != 4) {
		if (arr[i][r(top[i])] != arr[i + 1][l(top[i + 1])]) {
			change(i + 1, ccw ^ 1, 2);
		}
	}
	if (from != 2 && i != 1) {
		if (arr[i][l(top[i])] != arr[i - 1][r(top[i - 1])]) {
			change(i - 1, ccw ^ 1, 1);
		}
	}
	top[i] += ccw ? 1 : -1;
	top[i] = (top[i] + 8) % 8;
}

int main() {
	for (int i = 1; i <= 4; i++) {
		scanf("%s", arr[i]);
		top[i] = 0;
	}
	int ans = 0;
	int k; scanf("%d", &k);
	while (k--) {
		int q, w; scanf("%d %d", &q, &w);
		change(q, w != 1, 0);
	}
	printf("%d\n", (arr[1][top[1]] == '1') + 2 * (arr[2][top[2]] == '1') + 4 * (arr[3][top[3]] == '1') + 8 * (arr[4][top[4]] == '1'));
	return 0;
}