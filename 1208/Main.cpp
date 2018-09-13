#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n, s;
ll cnt = 0;
ll inp[55] = {};
int arr[8000010] = {};
const int plus_ = 4000000;

void back(ll now, ll sum) {
	if (now == n / 2 + 1) {
		arr[sum + plus_]++;
		return;
	}
	back(now + 1, sum);
	back(now + 1, sum + inp[now]);
}

void back2(ll now, ll sum) {
	if (now == n + 1) {
		cnt += arr[s - sum + plus_];
		return;
	}
	back2(now + 1, sum);
	back2(now + 1, sum + inp[now]);
}

int main() {
	scanf("%lld %lld", &n, &s);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
	}
	back(1, 0);
	back2(n / 2 + 1, 0);
	if (!s)cnt--;
	printf("%lld\n", cnt);
	return 0;
}