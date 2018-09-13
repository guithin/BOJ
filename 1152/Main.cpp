#include<stdio.h>
int main() {
	int cnt = 1;
	bool ed = false;
	bool flag = false;
	while (1) {
		char temp = getchar();
		if (temp == ' ') {
			if (flag == false)continue;
			ed = true;
			continue;
		}
		if (temp >= 'a'&&temp <= 'z') {
			if (ed == true)cnt++;
			ed = false;
			flag = true;
			continue;
		}
		if (temp >= 'A'&&temp <= 'Z') {
			if (ed == true)cnt++;
			ed = false;
			flag = true;
			continue;
		}
		else
			break;
	}
	if (flag == false) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", cnt);
	return 0;
}