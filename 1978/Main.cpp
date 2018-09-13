#include<bits/stdc++.h>
using namespace std;

bool arr[1010];

int main() {
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (arr[i])continue;
		for (int j = 2; i*j <= 1000; j++) {
			arr[i*j] = 1;
		}
	}
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		ans += !arr[temp];
	}
	printf("%d\n", ans);
	return 0;
}