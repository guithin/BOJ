#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x1, y1, x2, y2, r1, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else {
			int a = abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2);
			int b = abs(r2 - r1)*abs(r2 - r1);
			int c = abs(r2 + r1)*abs(r2 + r1);
			if (a == b || a == c)printf("1\n");
			else if (a < c && b < a)printf("2\n");
			else printf("0\n");
		}
	}
	return 0;
}