#include<stdio.h>
#include<algorithm>

struct pos {
	int start;
	int finish;
	pos() {};
	pos(int a, int b) {
		start = a;
		finish = b;
	}
	bool operator <(const pos&io) const {
		return start < io.start;
	}
};

pos input[100010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &input[i].start, &input[i].finish);
	}
	std::sort(input, input + n);
	int cnt = 1;
	int end = 10000000;
	for (int i = 0; i < n; i++) {
		if (input[i].finish < end) {
			end = input[i].finish;
		}
		else if (input[i].start >= end) {
			cnt++;
			end = input[i].finish;
//			printf("%d\n", i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}