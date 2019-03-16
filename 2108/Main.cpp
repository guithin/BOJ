#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

int bin[10000];
priority_queue<int>q;

int main() {
	int n; scanf("%d", &n);
	int maxx = -10000, minx = 10000;
	int av = 0;
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		av += t;
		maxx = max(maxx, t); minx = min(minx, t);
		bin[t + 4000]++;
		if (q.size() < (n + 1) / 2)q.push(t);
		else if (q.top() > t) {
			q.pop(); q.push(t);
		}
	}
	int a = 0, b = 0;
	for (int i = 0; i <= 8000; i++) {
		if (bin[i] > bin[a]) {
			a = i; b = 0;
		}
		else if (bin[i] == bin[a] && !b) {
			a = i; b = 1;
		}
	}
	printf("%d\n%d\n%d\n%d\n",
		av / n + (abs(av%n) * 2 >= n)*(av%n > 0 ? 1 : -1),
		q.top(),
		a - 4000,
		maxx - minx);
	return 0;
}