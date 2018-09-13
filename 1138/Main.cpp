#include<stdio.h>

int main() {
	int n;
	int arr[200] = { 0 };
	int ans[200] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (ans[j] == 0)temp++;
			if (temp > arr[i] && ans[j] == 0) {
				ans[j] = i;
/*				for (int k = 1; k <= n; k++) {
					printf("%d ", ans[k]);
				}
				printf("\n");*/
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}