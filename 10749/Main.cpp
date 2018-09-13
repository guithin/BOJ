#include<stdio.h>
#include<queue>

struct pos {
	int i, o, val;
	pos() {};
	pos(int a, int b, int c) {
		i = a; o = b; val = c;
	}
	bool operator<(const pos&io)const {
		return val < io.val;
	}
};

int n;
int inp[2010] = { 0 };
int mot[2010] = { 0 };
std::priority_queue<pos>q;

int find(int x) {
	if (mot[x] == x)return x;
	return mot[x] = find(mot[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	for (int i = 1; i <= n; i++) {
		mot[i] = i;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			q.push(pos(i, j, inp[i] ^ inp[j]));
		}
	}
	long long sum = 0;
	int cnt = 0;
	while (cnt != n - 1) {
		pos now = q.top(); q.pop();
		if (find(now.i) != find(now.o)) {
			mot[find(now.i)] = find(now.o);
			sum += now.val;
			cnt++;
		}
	 }
	printf("%lld\n", sum);
	return 0;
}