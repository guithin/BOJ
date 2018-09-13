#include<stdio.h>
#include<memory.h>
#include<string.h>

struct pos {
	char str[1010];
	int idx;
	pos() {
		memset(str, 0, sizeof(str));
		idx = 0;
	}
};

pos inp[30];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp[i].str);
	}
	while (1) {
		char c = 'Z' + 1;
		int myi = 0;
		for (int i = 1; i <= n; i++) {
			if (!inp[i].str[inp[i].idx])continue;
			if (inp[i].str[inp[i].idx] < c) {
				c = inp[i].str[inp[i].idx];
				myi = i;
			}
			else if (inp[i].str[inp[i].idx] == c) {
				int ti1 = inp[myi].idx;
				int ti2 = inp[i].idx;
				while (inp[myi].str[ti1] == inp[i].str[ti2]) {
					ti1++; ti2++;
				}
				if (inp[myi].str[ti1] == 0 || (inp[myi].str[ti1] > inp[i].str[ti2] && inp[i].str[ti2] != 0)) {
					myi = i;
				}
			}
		}
		if (!myi)break;
		printf("%c", c);
		inp[myi].idx++;
	}
	printf("\n");
	return 0;
}