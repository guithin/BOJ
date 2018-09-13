#include<stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a != b) {
			printf("Wrong Answer\n");
			return 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a != b) {
			printf("Why Wrong!!!\n");
			return 0;
		}
	}
	printf("Accepted\n");
	return 0;
}