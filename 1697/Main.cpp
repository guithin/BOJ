#include<stdio.h>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<memory.h>
using namespace std;

int n, k;
int arr[100110];
queue<int>q;

int main() {
	memset(arr, 40, sizeof(arr));
	scanf("%d %d", &n, &k);
	arr[n] = 0;
	q.push(n);
	while (q.size()) {
		int now = q.front(); q.pop();
		if (now == k)break;
		if (now - 1 >= 0 && arr[now - 1] > arr[now] + 1) {
			arr[now - 1] = arr[now] + 1; q.push(now - 1);
		}
		if (now < 100100&&arr[now+1]>arr[now]+1) {
			arr[now + 1] = arr[now] + 1; q.push(now + 1);
		}
		if (now * 2 <= 100100 && arr[now * 2] > arr[now] + 1) {
			arr[now * 2] = arr[now] + 1; q.push(now * 2);
		}
	}
	printf("%d\n", arr[k]);
	return 0;
}