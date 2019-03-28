#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;

int arr[2][500010];
queue<int>q[2];

bool range(int x) {
	return 0 <= x && x <= 500000;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(arr, 40, sizeof(arr));
	arr[0][n] = 0;
	q[0].push(n);
	while (q[0].size() || q[1].size()) {
		while (q[0].size()) {
			int now = q[0].front(); q[0].pop();
			if (range(now - 1) && arr[1][now - 1] > arr[0][now] + 1) {
				arr[1][now - 1] = arr[0][now] + 1;
				q[1].push(now - 1);
			}
			if (range(now + 1) && arr[1][now + 1] > arr[0][now] + 1) {
				arr[1][now + 1] = arr[0][now] + 1;
				q[1].push(now + 1);
			}
			if (range(now * 2) && arr[1][now * 2] > arr[0][now] + 1) {
				arr[1][now * 2] = arr[0][now] + 1;
				q[1].push(now * 2);
			}
		}
		while (q[1].size()) {
			int now = q[1].front(); q[1].pop();
			if (range(now - 1) && arr[0][now - 1] > arr[1][now] + 1) {
				arr[0][now - 1] = arr[1][now] + 1;
				q[0].push(now - 1);
			}
			if (range(now + 1) && arr[0][now + 1] > arr[1][now] + 1) {
				arr[0][now + 1] = arr[1][now] + 1;
				q[0].push(now + 1);
			}
			if (range(now * 2) && arr[0][now * 2] > arr[1][now] + 1) {
				arr[0][now * 2] = arr[1][now] + 1;
				q[0].push(now * 2);
			}
		}
	}
	int ans = 0;
	while (1) {
		if (m > 500000)break;
		if (arr[ans&1][m] <= ans) {
			printf("%d\n", ans);
			return 0;
		}
		m += ++ans;
	}
	printf("-1\n");
	return 0;
}