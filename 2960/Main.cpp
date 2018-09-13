#include<stdio.h>

int arr[10010] = { 1,1 };

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 1)continue;
		arr[i] = 1;
		cnt++;
		if (cnt == k) {
			printf("%d\n", i);
			return 0;
		}
		for (int j = 2; i*j <= n; j++) {
			if (arr[i*j] == 1)continue;
			arr[i*j] = 1;
			cnt++;
			if (cnt == k) {
				printf("%d\n", i*j);
				return 0;
			}
		}
	}
	return 0;
}