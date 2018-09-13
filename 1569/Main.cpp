#include<stdio.h>
#include<algorithm>

int inpx[110] = { 0 };
int inpy[110] = { 0 };
int tempx[110] = { 0 };
int tempy[110] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", inpx + i, inpy + i);
		tempx[i] = inpx[i];
		tempy[i] = inpy[i];
	}
	std::sort(inpx + 1, inpx + 1 + n);
	std::sort(inpy + 1, inpy + 1 + n);
	int x1 = inpx[1];
	int x2 = inpx[n];
	int y1 = inpy[1];
	int y2 = inpy[n];
	int ran = std::max(x2 - x1, y2 - y1);
	for (int i = 1; i <= 4; i++) {
		int nx1, ny1, nx2, ny2;
		if (i == 1) {
			nx1 = x1; ny1 = y1;
			nx2 = nx1 + ran;
			ny2 = ny1 + ran;
		}
		else if (i == 2) {
			nx2 = x2; ny1 = y1;
			nx1 = nx2 - ran;
			ny2 = ny1 + ran;
		}
		else if (i == 3) {
			nx1 = x1; ny2 = y2;
			nx2 = nx1 + ran;
			ny1 = ny2 - ran;
		}
		else if (i == 4) {
			nx2 = x2; ny2 = y2;
			nx1 = nx2 - ran;
			ny1 = ny2 - ran;
		}
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (tempx[j] != nx1&&tempx[j] != nx2&&tempy[j] != ny1&&tempy[j] != ny2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("%d\n", ran);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}