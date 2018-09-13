#include<stdio.h>
#include<queue>
using namespace std;

queue <int> q;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	printf("\n");
	return 0;
}