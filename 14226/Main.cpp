#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;

struct pos {
	int now, temp, cost;
	pos() {};
	pos(int a, int b, int c) {
		now = a; temp = b; cost = c;
	}
	bool operator==(const pos&io)const {
		return now == io.now&&temp == io.temp;
	}
};

int dp[5010][3010];
queue<pos>q;

int main() {
	int n;
	scanf("%d", &n);
	q.push(pos(1, 0, 0));
	while (q.size()) {
		pos now = q.front(); q.pop();
		if (now.now != now.temp && now.now < 1200)
			q.push(pos(now.now, now.now, now.cost + 1));
		if (now.temp && now.now + now.temp < 1200 && dp[now.now + now.temp][now.temp] == 0) {
			dp[now.now + now.temp][now.temp] = 1;
			if (now.now + now.temp == n) {
				printf("%d\n", now.cost + 1);
				return 0;
			}
			q.push(pos(now.now + now.temp, now.temp, now.cost + 1));
		}
		if (now.now > 1 && dp[now.now-1][now.temp]==0) {
			dp[now.now - 1][now.temp] = 1;
			if (now.now - 1 == n) {
				printf("%d\n", now.cost + 1);
				return 0;
			}
			q.push(pos(now.now - 1, now.temp, now.cost + 1));
		}
	}
	return 0;
}