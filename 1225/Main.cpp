#include<stdio.h>

char str1[10010];
char str2[10010];

int main() {
	scanf("%s %s", str1, str2);
	long long sum = 0;
	for (long long i = 0; str1[i] != 0; i++) {
		for (long long j = 0; str2[j] != 0; j++) {
			sum += (str1[i] - '0')*(str2[j] - '0');
		}
	}
	printf("%lld\n", sum);
	return 0;
}