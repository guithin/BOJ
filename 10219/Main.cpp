#include<stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, w;
		scanf("%d %d", &h, &w);
		int map[20][20] = {};
		for (int i = 1; i <= h; i++) {
			scanf("%s", map[i]);
		}
		for (int i = h; i >= 1; i--) {
			printf("%s\n", map[i]);
		}
	}
	return 0;
}