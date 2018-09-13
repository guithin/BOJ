#include<stdio.h>
#include<string.h>

char a[55] = { 0 };
char b[55] = { 0 };

int main() {
	scanf("%s %s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int mini = 987654321;
	int temp = 0;
	for (int i = 0; i <= lenb-lena; i++) {
		int t = 0;
		for (int j = 0; j < lena; j++) {
//			printf("%c %c\n", a[j], b[i+j]);
			if (a[j] != b[i+j])t++;
		}
//		printf("%d\n", t);
		if (mini > t) {
			mini = t;
			temp = i;
		}
	}
	printf("%d\n", mini);
	return 0;
}