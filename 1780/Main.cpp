#include<stdio.h>
int cz = 0;
int co = 0;
int cm = 0;
int map[3000][3000] = { 0 };

void div(int xs, int xe, int ys, int ye) {
	int flag = true;
	for (int i = xs + 1; i <= xe; i++) {
		for (int j = ys + 1; j <= ye; j++) {
			int temp = map[xs + 1][ys + 1];
			if (map[i][j] != temp) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}
	if (flag == true) {
		if (map[xs + 1][ys + 1] == -1)
			cm++;
		else if (map[xs + 1][ys + 1] == 0)
			cz++;
		else if (map[xs + 1][ys + 1] == 1)
			co++;
		flag = false;
		return;
	}

	div(xs, xs + (xe - xs) / 3, ys, ys + (ye - ys) / 3);
	div(xs + (xe - xs) / 3, xs + (xe - xs)*2 / 3, ys, ys + (ye - ys) / 3);
	div(xs + (xe - xs)*2 / 3, xs + (xe - xs), ys, ys + (ye - ys) / 3);

	div(xs, xs + (xe - xs) / 3, ys+(ye - ys) / 3, ys + (ye - ys) *2/ 3);
	div(xs + (xe - xs) / 3, xs + (xe - xs) * 2 / 3, ys+(ye - ys) / 3, ys + (ye - ys)*2 / 3);
	div(xs + (xe - xs) * 2 / 3, xs + (xe - xs), ys+(ye - ys) / 3, ys + (ye - ys) *2/ 3);

	div(xs, xs + (xe - xs) / 3, ys+(ye - ys)*2 / 3, ys + (ye - ys));
	div(xs + (xe - xs) / 3, xs + (xe - xs) * 2 / 3, ys+(ye - ys) *2/ 3, ys + (ye - ys));
	div(xs + (xe - xs) * 2 / 3, xs + (xe - xs), ys+(ye - ys)*2 / 3, ys + (ye - ys));
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	div(0, n, 0, n);
	printf("%d\n%d\n%d\n", cm, cz, co);
	return 0;
}