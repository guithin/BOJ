#include "stdio.h"
int arr[12];
int when[12];
int main(void)
{
	int N, cnt = 0;
	scanf("%d", &N);
	while (N--) {
		int num, dir;
		scanf("%d %d", &num, &dir);
		if (when[num] == 1) {
			if (dir != arr[num]) {
				cnt++;
			}
		}

		when[num] = 1;
		arr[num] = dir;
	}
	printf("%d\n", cnt);
	return 0;
}