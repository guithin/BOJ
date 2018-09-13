#include<stdio.h>
struct pos {
	int map[10][2];
	void main() {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 10; i++)map[i][0] = 1;
		for (int i = 2; i <= n; i++) {
			map[0][1] = map[7][0];
			map[1][1] = map[2][0] + map[4][0];
			map[2][1] = map[1][0] + map[5][0] + map[3][0];
			map[3][1] = map[2][0] + map[6][0];
			map[4][1] = map[1][0] + map[5][0] + map[7][0];
			map[5][1] = map[2][0] + map[4][0] + map[6][0] + map[8][0];
			map[6][1] = map[3][0] + map[5][0] + map[9][0];
			map[7][1] = map[4][0] + map[8][0] + map[0][0];
			map[8][1] = map[7][0] + map[5][0] + map[9][0];
			map[9][1] = map[8][0] + map[6][0];
			for (int j = 0; j < 10; j++) {
				map[j][0] = map[j][1] % 1234567;
			}
		}
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += map[i][0];
			sum %= 1234567;
		}
		printf("%d\n", sum);
		return;
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		pos temp;
		temp.main();
	}
	return 0;
}