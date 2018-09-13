#include<stdio.h>
#include<string.h>

char str[100] = { 0 };
long long lv[15][100] = { 0 };

int main() {
	for (int i = 1; i <= 80; i++) {
		if (i == 1) {
			for (int j = 0; j < 10; j++) {
				lv[j][i] = 1;
			}
			continue;
		}
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				lv[j][i] += lv[k][i - 1];
			}
		}
	}
/*	for (int i = 1; i <= 80; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%lld ", lv[j][i]);
		}
		printf("\n");
	}*/
	int t;
	scanf("%d", &t);
	while (t--) {
		bool flag = false;
		long long sum = 0;
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			str[i] -= '0';
			if (i == 0)continue;
			if (str[i - 1] > str[i]) {
				printf("%lld\n", (long long)-1);
				flag = true;
				break;
			}
		}
		if (flag)continue;
		long long ans = 0;
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				for (int le = 0; le < str[i]; le++) {
					sum += lv[le][len];
				}
				continue;
			}

			for (int le = str[i-1]; le < str[i]; le++) {
				sum += lv[le][len-i];
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}