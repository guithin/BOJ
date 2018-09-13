#include<bits/stdc++.h>
using namespace std;

int arr[200010];
int path[200010];//1->x-1, 2->x+1, 3->x*2, 4->start
queue<int>q;
vector<int>vec;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n >= m) {
		printf("%d\n", n - m);
		for (int i = n; i >= m; i--)printf("%d ", i);
		return 0;
	}
	arr[n] = 1;
	path[n] = 4;
	q.push(n);
	while (q.size()) {
		int now = q.front(); q.pop();
		if (now - 1 > 0 && !arr[now - 1]) {
			arr[now - 1] = arr[now] + 1;
			path[now - 1] = 1;
			q.push(now - 1);
		}
		if (now + 1 <= 200000 && !arr[now + 1]) {
			arr[now + 1] = arr[now] + 1;
			path[now + 1] = 2;
			q.push(now + 1);
		}
		if (now * 2 <= 200000 && !arr[now * 2]) {
			arr[now * 2] = arr[now] + 1;
			path[now * 2] = 3;
			q.push(now * 2);
		}
		if (arr[m])break;
	}
	printf("%d\n", arr[m] - 1);
	while (path[m] != 4) {
		vec.push_back(m);
		if (path[m] == 1)m++;
		else if (path[m] == 2)m--;
		else if (path[m] == 3)m /= 2;
	}
	printf("%d ", n);
	for (int i = vec.size() - 1; i + 1; i--) {
		printf("%d ", vec[i]);
	}
	return 0;
}