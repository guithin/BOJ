#include<algorithm>
#include<queue>
#include<stdio.h>
using namespace std;

void getinp(int &x) {
	x = 0;
	char c; bool flag = false;
	bool m = false;
	while (1) {
		c = getchar();
		if (c == ' ' || c == '\n' || c == EOF) {
			if (flag)break;
			continue;
		}
		if (c == '-') {
			m = true;
			continue;
		}
		x *= 10; x += c - '0';
		flag = true;
	}
	if (m)x *= -1;
}

int main() {
	int n, k;
	getinp(n); getinp(k);
	priority_queue<int>q;
	if (k < n / 2) {
		for (int i = 1; i <= n; i++) {
			int a; getinp(a);
			if (q.size() < k)q.push(a);
			else {
				if (q.top() > a) {
					q.pop(); q.push(a);
				}
			}
		}
		printf("%d\n", q.top());
	}
	else {
		for (int i = 1; i <= n; i++) {
			int a; getinp(a);
			if (q.size() < n - k + 1)q.push(-a);
			else {
				if (-q.top() < a) {
					q.pop(); q.push(-a);
				}
			}
		}
		printf("%d\n", -q.top());
	}
	return 0;
}