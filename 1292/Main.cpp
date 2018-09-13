#include<stdio.h>

int map[1010] = { 0 };

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int cnt = 1;
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			map[cnt++] = i;
			if (cnt > b)break;
		}
		if (cnt > b)break;
	}
	for (int i = a; i < b; i++) {
		map[i + 1] += map[i];
	}
	printf("%d\n", map[b]);
	return 0;
}