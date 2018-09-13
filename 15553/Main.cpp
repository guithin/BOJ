#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
typedef long long ll;

ll n, k;
ll inp[100010];
priority_queue<int>q;

int main() {
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
	}
	ll sum = inp[n] - inp[1] + 1;
	for (ll i = 1; i < n; i++) {
		q.push(inp[i + 1] - inp[i]);
	}
	k--;
	while (k--) {
		if (!q.size())break;
		sum -= q.top() - 1;
		q.pop();
	}
	printf("%lld\n", sum);
	return 0;
}