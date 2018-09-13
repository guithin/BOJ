#include<bits/stdc++.h>
using namespace std;

int n;
bool hans(int x) {
	int arr[5] = {};
	int j = 0;
	while (x) {
		arr[j++] = x % 10;
		x /= 10;
	}
	int temp = arr[1] - arr[0];
	for (int i = 1; i < j; i++) {
		if (arr[i] - arr[i - 1] != temp)return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	int ans = min(99, n);
	for (int i = 111; i <= n; i++) {
		if (hans(i)) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}