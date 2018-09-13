#include<stdio.h>

int pick[100];
int arr[100];

void printlotto(int n, int idx, int k) {
	if (n == 6) {
		for (int i = 0; i < n; i++) {
			printf("%d ", pick[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < k; i++) {
		pick[n] = arr[i];
		printlotto(n + 1, i + 1,k);
	}

}

int main() {
	while (1) {
		int k;
		scanf("%d", &k);
		if (k == 0)
			return 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &arr[i]);
		}

		printlotto(0, 0,k);
		printf("\n");
	}
	return 0;
}