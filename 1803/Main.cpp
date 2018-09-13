#include<stdio.h>
#include<queue>

int m, n;
int input1[50010] = { 0 };
int tar1[50010] = { 0 };
int input2[50010] = { 0 };
int tar2[50010] = { 0 };
int ans1[50010] = { 0 };
int ans2[50010] = { 0 };

std::queue <int> q1;
std::queue <int> q2;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input1[i]);
		tar2[input1[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &input2[i]);
		tar1[input2[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (tar1[i] == 0) {
			q1.push(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (tar2[i] == 0) {
			q2.push(i);
		}
	}

	while (1) {
		if (q1.size() == 0 && q2.size() == 0)break;
		if (q1.size() != 0) {
			int i = q1.front();
			q1.pop();
			ans1[i] = 2;
			if (ans2[input1[i]] == 0) {
				ans2[input1[i]] = 1;
				tar1[input2[input1[i]]]--;
				if (tar1[input2[input1[i]]] == 0 && ans1[input2[input1[i]]]==0)
					q1.push(input2[input1[i]]);
			}
		}
		if (q2.size() != 0) {
			int i = q2.front();
			q2.pop();
			ans2[i] = 2;
			if (ans1[input2[i]] == 0) {
				ans1[input2[i]] = 1;
				tar2[input1[input2[i]]]--;
				if (tar2[input1[input2[i]]] == 0 && ans2[input1[input2[i]]] == 0)
					q2.push(input1[input2[i]]);
			}
		}
	}

/*	while (1) {
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (ans1[i] == 0 && tar1[i] == 0) {
				flag = false;
				ans1[i] = 2;
				if (ans2[input1[i]] == 0) {
					ans2[input1[i]] = 1;
					tar1[input2[input1[i]]]--;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			if (ans2[i] == 0 && tar2[i] == 0) {
				flag = false;
				ans2[i] = 2;
				if (ans1[input2[i]] == 0) {
					ans1[input2[i]] = 1;
					tar2[input1[input2[i]]]--;
				}
			}
		}
		if (flag)break;
	}*/
	for (int i = 1; i <= n; i++) {
		if (ans1[i] == 0) {
			if (ans2[input1[i]] < 2) {
				ans1[i] = 2;
				ans2[input1[i]] = 1;
			}
			else
				ans1[i] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (ans2[i] == 0) {
			if (ans1[input2[i]] < 2) {
				ans2[i] = 2;
				ans1[input2[i]] = 1;
			}
			else
				ans2[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d", ans1[i]-1);
	}
	printf("\n");
	for (int i = 1; i <= m; i++) {
		printf("%d", ans2[i]-1);
	}
	printf("\n");
	return 0;
}