#include<stdio.h>
#include<queue>
#include<algorithm>

struct pos {
	int i, val;
	pos() {};
	pos(int a, int b) {
		i = a;
		val = b;
	}
	bool operator  <(const pos&io)const {
		return i < io.i;
	}
};

pos arr[10];
std::priority_queue<int>q;

bool cmp(pos a, pos b) {
	return a.val < b.val;
}

int main() {
	int n = 8;
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[i] = pos(i, temp);
	}
	std::sort(arr + 1, arr + 1 + n, cmp);
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += arr[n - i].val;
		q.push(-arr[n - i].i);
	}
	printf("%d\n", ans);
	while (!q.empty()) {
		printf("%d ", -q.top());
		q.pop();
	}
	printf("\n");
	return 0;
}