#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct pos {
	int start_time, number;
	pos(int q, int w) {
		start_time = q;
		number = w;
	}
};

int sang_delay, jisu_delay, n;
vector<pos>sang_task;
vector<pos>jisu_task;

vector<int>sang_ans;
vector<int>jisu_ans;

int main() {
	scanf("%d %d %d", &sang_delay, &jisu_delay, &n);
	for (int i = 1; i <= n; i++) {
		char c;
		int q, w;
		scanf("%d %c %d", &q, &c, &w);
		if (c == 'B') {
			sang_task.push_back(pos(q, w));
		}
		else {
			jisu_task.push_back(pos(q, w));
		}
	}
	int sang = sang_task[0].start_time, sidx = 0;
	int jisu = jisu_task[0].start_time, jidx = 0;
	int k = 1;
	while (1) {
		if (sang_task.size() > sidx && sang <= jisu) {
			sang_ans.push_back(k++);
			sang_task[sidx].number--;
			sang += sang_delay;
			if (sang_task[sidx].number == 0) {
				sidx++;
				if (sidx < sang_task.size())
					sang = max(sang, sang_task[sidx].start_time);
				else
					sang = 1234567890;
			}
		}
		else if (jisu_task.size() > jidx) {
			jisu_ans.push_back(k++);
			jisu_task[jidx].number--;
			jisu += jisu_delay;
			if (jisu_task[jidx].number == 0) {
				jidx++;
				if (jidx < jisu_task.size())
					jisu = max(jisu, jisu_task[jidx].start_time);
				else
					jisu = 1234567890;
			}
		}
		else break;
	}
	printf("%d\n", sang_ans.size());
	for (int i : sang_ans)printf("%d ", i);
	printf("\n");
	printf("%d\n", jisu_ans.size());
	for (int i : jisu_ans)printf("%d ", i);
	printf("\n");
	return 0;
}