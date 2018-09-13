#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long ll;

ll arr[1000010];
queue<int>q;

int main() {
	ll f, s, g, u, d;
	scanf("%lld %lld %lld %lld %lld", &f, &s, &g, &u, &d);
	memset(arr, 40, sizeof(arr));
	arr[s] = 0;
	q.push(s);
	while (q.size()) {
		ll now = q.front(); q.pop();
		if (now - d >= 1) {
			if (arr[now - d] > arr[now] + 1) {
				arr[now - d] = arr[now] + 1;
				q.push(now - d);
			}
		}
		if (now + u <= f) {
			if (arr[now + u] > arr[now] + 1) {
				arr[now + u] = arr[now] + 1;
				q.push(now + u);
			}
		}
	}
	if (arr[g] < arr[0]) {
		printf("%d\n", arr[g]);
	}
	else
		printf("use the stairs\n");
	return 0;
}