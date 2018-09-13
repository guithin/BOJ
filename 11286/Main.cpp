#include <stdio.h>
#include <queue>
using namespace std;

int fabsx(int x) {
	return x < 0 ? -x : x;
}

struct Elem {
	int value, absx;
	Elem(int v) {
		value = v;
		absx = fabsx(v);
	}

	bool operator <(const Elem &o)const {
		if (absx == o.absx) return value > o.value;
		return absx > o.absx;
	}
};

int main()
{
	priority_queue<Elem> pq;
	int N; scanf("%d", &N);
	while (N--) {
		int x; scanf("%d", &x);

		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(Elem(x));
		}
	}
	return 0;
}