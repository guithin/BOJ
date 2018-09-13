#include<stdio.h>
#include<string.h>
#include<vector>
#include<memory.h>

char str[1000010] = { 0 };
char ans[1000010] = { 0 };
char pok[1000010] = { 0 };
int pi[1000010] = { 0 };
bool chk[1000010] = { 0 };
int pil[1000010] = { 0 };
int idx = 0;
int c = 0;

int main() {
	scanf("%s %s", str, pok);
	int plen = strlen(pok);
	int slen = strlen(str);
	for (int i = 1; i <= plen; i++) {
		while (idx&&pok[idx] != pok[i])
			idx = pi[idx - 1];
		if (pok[idx] == pok[i])
			pi[i] = ++idx;
	}
	idx = 0;
	for (int i = 0; i < slen; i++) {
		ans[c] = str[i];
		while (idx && ans[c] != pok[idx]) {
			idx = pi[idx - 1];
		}
		if (ans[c] == pok[idx]) {
			if (idx == plen - 1) {
				c -= plen;
				if (c < 0)idx = 0;
				else idx = pil[c];
				memset(pil + c + 1, 0, plen * 4);
			}
			else {
				pil[c] = ++idx;
			}
		}
		c++;
		ans[c] = 0;
	}
	printf("%s", ans);
	return 0;
}