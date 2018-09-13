#include<stdio.h>

char str[1000010];
int save[1000010];

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	scanf("%s", str);

	for (int i = 2; i < s; i++) {
		if (str[i] == 'I'&&str[i - 1] == 'O'&&str[i - 2] == 'I') {
			save[i] = save[i - 2] + 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= s; i++) {
		if (save[i] >= n)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}