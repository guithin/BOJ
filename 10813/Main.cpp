#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[110] = {};
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}