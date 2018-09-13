#include<stdio.h>

char str[110] = { 0 };
long long under[15] = { 0 };
long long idx = 0;
long long cnt = 0;

void back(long long cur, long long temp) {
	if (cur == idx) {
		bool L = false;
		long long mo[110] = { 0 };
		long long ja[110] = { 0 };
		for (long long i = 0; str[i] != 0; i++) {
			if (str[i] == 'L')L = true;
			if (i == 0) {
				if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
					mo[i] = 1;
				}
				else
					ja[i] = 1;
				continue;
			}
			if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
				mo[i] = mo[i-1]+1;
				if (mo[i] >= 3)return;
			}
			else {
				ja[i] = ja[i - 1] + 1;
				if (ja[i] >= 3)return;
			}
		}
		if (L) {
			cnt += temp;
		}
		return;
	}
	str[under[cur]] = 'A';
	back(cur + 1, temp*5);
	str[under[cur]] = 'L';
	back(cur + 1, temp);
	str[under[cur]] = 'K';
	back(cur + 1, temp*20);
}

int main() {
	scanf("%s", str);
	for (long long i = 0; str[i] != 0; i++) {
		if (str[i] == '_') {
			under[idx] = i;
			idx++;
		}
	}
	back(0, 1);
	printf("%lld\n", cnt);
	return 0;
}