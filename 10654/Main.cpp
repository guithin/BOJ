#include<stdio.h>
#include<algorithm>
#include<stack>

struct pos {
	int init, spd;
	pos() {};
	pos(int a, int b) {
		init = a;
		spd = b;
	}
	bool operator<(const pos&io)const {
		return init < io.init;
	}
};

int n, t;
pos inp[100010];
std::stack<pos>stk;

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inp[i].init, &inp[i].spd);
	}
	std::sort(inp + 1, inp + 1 + n);
	int grp = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			stk.push(inp[i]);
			continue;
		}
		while (1) {
			if (stk.top().spd <= inp[i].spd)break;
			int time = (inp[i].init - stk.top().init) / (stk.top().spd - inp[i].spd);
			if ((inp[i].init - stk.top().init) % (stk.top().spd - inp[i].spd))
				time++;
			if (time <= t)stk.pop();
			else
				break;
			if (stk.empty())break;
		}
		stk.push(inp[i]);
	}
	printf("%d\n", stk.size());
	return 0;
}