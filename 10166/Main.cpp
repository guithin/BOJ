#include<stdio.h>

int gcd(int a, int b) {
	return a%b ? gcd(b, a%b) : b;
}

int d1, d2;
int map[2010][2010];

int main() {
	scanf("%d %d", &d1, &d2);
	int cnt = 1;
	for (int i = d1; i <= d2; i++)map[0][i] = 1;
	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j < i; j++) {
			int g = gcd(i, j);
			int a = i / g;
			int b = j / g;
			if (!map[b][a]) {
				cnt++;
				map[b][a] = 1;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}