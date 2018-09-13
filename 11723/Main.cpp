#include<stdio.h>

int main() {
	int ans = 0;
	int cur;
	scanf("%d", &cur);
	for (int i = 1; i <= cur; i++) {
		char temp[20] = { 0 };
		scanf("%s", temp);
		if (temp[0] == 'a' && temp[1] == 'd') {
			int num;
			scanf("%d", &num);
			ans |= (1 << num);
		}
		else if (temp[0] == 'r') {
			int num;
			scanf("%d", &num);
			ans &= ((-1)^(1 << num));
		}
		else if (temp[0] == 'c') {
			int num;
			scanf("%d", &num);
			printf("%d\n", ans&(1 << num) ? 1 : 0);
		}
		else if (temp[0] == 't') {
			int num;
			scanf("%d", &num);
			if (ans&(1 << num))ans -= (1 << num);
			else ans += (1 << num);
		}
		else if (temp[0] == 'a') {
			ans = -1;
		}
		else if (temp[0] == 'e') {
			ans = 0;
		}
	}
	return 0;
}