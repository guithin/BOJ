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

int n;
pos inp[100010];
std::stack<int>stk;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inp[i].init, &inp[i].spd);
	}
	std::sort(inp + 1, inp + 1 + n);
	int grp = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			stk.push(inp[i].spd);
			continue;
		}
		while (stk.top() > inp[i].spd) {
			stk.pop();
			if (stk.empty())break;
		}
		stk.push(inp[i].spd);
	}
	printf("%d\n", stk.size());
	return 0;
}