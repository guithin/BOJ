#include<bits/stdc++.h>
using namespace std;

int n, ans;
char str[110];
char inp[22][22];

int main() {
	scanf("%s", str);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp[i]);
		for (int j = 0; str[j]; j++) {
			int t = (str[j] - inp[i][0] + 26) % 26;
			bool flag = true;
			for (int k = 0; inp[i][k]; k++) {
				if ((str[j + k] - inp[i][k] + 26) % 26 != t) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans = t;
				break;
			}
		}
		if (ans)break;
	}
	for (int i = 0; str[i]; i++) {
		printf("%c", (str[i] - ans - 'a' + 26) % 26 + 'a');
	}
	printf("\n");
	return 0;
}