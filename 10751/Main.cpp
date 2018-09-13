#include<stdio.h>

int dp[100010][5] = { 0 };
char str[100010] = { 0 };
long long c, o, w;
long long sum = 0;

int main() {
	long long n;
	scanf("%lld", &n);
	scanf("%s", str);
	for (long long i = 0; str[i] != 0; i++) {
		if (str[i] == 'C')c++;
		if (str[i] == 'O') {
			o += c;
		}
		if (str[i] == 'W')
			sum += o;
	}
	printf("%lld\n", sum);
	return 0;
}