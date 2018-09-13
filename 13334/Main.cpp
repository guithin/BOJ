#include<stdio.h>
#include<queue>
#include<algorithm>

struct pos {
	int start;
	int end;
	pos() {};
	pos(int a, int b) {
		start = a;
		end = b;
	}
	bool operator <(const pos&io)const {
		return start>io.start;
	}
};

bool cmp(pos a, pos b) {
	return a.end<b.end;
}

pos input[100010];
bool chk[100010] = { 0 };
std::priority_queue<pos>que;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a <= b)
			input[i] = pos(a, b);
		else
			input[i] = pos(b, a);
	}
	std::sort(input + 1, input + 1 + n, cmp);
	int len;
	scanf("%d", &len);
	int cnt = 0;
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int lend = input[i].end;
		int lstart = lend - len;
		while (!que.empty()&&que.top().start<lstart) {
			que.pop();
			cnt--;
		}
		if (input[i].end - input[i].start <= len) {
			que.push(input[i]);
			cnt++;
			if (maxi<cnt)maxi = cnt;
		}
	}
	printf("%d\n", maxi);
	return 0;
}
