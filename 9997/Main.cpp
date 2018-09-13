#include<stdio.h>
#include<string.h>

char str[30][110] = { 0 };
int qwer[30] = { 0 };
int cnt = 0;
int n;

void back(int cur, int asdf) {
	if (cur == n + 1) {
		if (asdf == (1 << 26) - 1)cnt++;
		return;
	}
	int len = strlen(str[cur]);
	back(cur + 1, asdf);
	asdf = asdf | qwer[cur];
	back(cur + 1, asdf);
}

int main() {
	scanf("%d", &n);
	scanf("\n");
	for (int i = 1; i <= n; i++) {
		while (1) {
			char c = getchar();
			if (c == '\n' || c == EOF)break;
			else qwer[i] |= (1 << (c - 'a'));
		}
	}
	back(1, 0);
	printf("%d\n", cnt);
	return 0;
}