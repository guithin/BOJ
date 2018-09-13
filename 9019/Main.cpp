#include<stdio.h>
#include<queue>
#include<memory.h>

std::queue<int>que;
char stack[10010] = { 0 };
int idx = 0;

int D(int x) {
	return (2 * x) % 10000;
}
int S(int x) {
	if (!x)return 9999;
	return x - 1;
}
int L(int x) {
	x *= 10;
	int temp = x / 10000;
	x %= 10000;
	x += temp;
	return x;
}
int R(int x) {
	int temp = x % 10;
	x /= 10;
	x += temp * 1000;
	return x;
}

struct pos {
	int x;
	char a;
	pos() {};
	pos(int b, char c) {
		x = b;
		a = c;
	}
};

pos table[10000];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(table, 0, sizeof(table));
		idx = 0;
		int a, b;
		scanf("%d %d", &a, &b);
		que.push(a);
		while (que.size()) {
			int now = que.front();
			que.pop();
			if (now == b)break;
			if (!table[D(now)].a) {
				table[D(now)] = pos(now, 'D');
				que.push(D(now));
			}
			if (!table[S(now)].a) {
				table[S(now)] = pos(now, 'S');
				que.push(S(now));
			}
			if (!table[L(now)].a) {
				table[L(now)] = pos(now, 'L');
				que.push(L(now));
			}
			if (!table[R(now)].a) {
				table[R(now)] = pos(now, 'R');
				que.push(R(now));
			}
		}
		while (que.size())que.pop();
		int asdf = b;
		while (asdf != a) {
			stack[idx] = table[asdf].a;
			asdf = table[asdf].x;
			idx++;
		}
		for (int i = idx - 1; i >= 0; i--) {
			printf("%c", stack[i]);
		}
		printf("\n");
	}
	return 0;
}