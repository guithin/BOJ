#include<stdio.h>
#include<algorithm>
#include<memory.h>

struct pos {
	int old;
	char str[110];
	int idx;
	pos() {
		memset(str, 0, sizeof(str));
	};
	bool operator<(const pos&io)const {
		if (old != io.old) {
			return old < io.old;
		}
		return idx < io.idx;
	}
};

int n;
pos inp[100010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inp[i].old);
		scanf("%s", inp[i].str);
		inp[i].idx = i;
	}
	std::sort(inp + 1, inp + 1 + n);
	for (int i = 1; i <= n; i++) {
		printf("%d %s\n", inp[i].old, inp[i].str);
	}
	return 0;
}