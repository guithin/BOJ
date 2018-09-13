#include<stdio.h>
#include<queue>

std::priority_queue<long long>q;

int main() {
	long long n;
	scanf("%lld", &n);
	for (long long i = 1; i <= n*n; i++) {
		long long temp;
		scanf("%lld", &temp);
		if (q.size() < n) {
			q.push(-temp);
			continue;
		}
		if (-q.top() < temp) {
			q.pop();
			q.push(-temp);
		}
	}
	printf("%lld\n", -q.top());
	return 0;
}