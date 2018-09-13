#include<stdio.h>

int main() {
	int t;
	for (scanf("%d", &t); t; t--) {
		int n;
		scanf("%d", &n);
		int num = 0;
		bool so = false;
		while (n--) {
			if (so == false) {
				so = true;
			}
			else {
				so = false;
				num++;
			}

			if (so) {
				num *= 2;
				num++;
				so = false;
			}
			else {
				num *= 2;
			}
		}
		printf("%d", num);
		if (so)printf(".5");
		printf("\n");
	}
	return 0;
}