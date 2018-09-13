#include<stdio.h>

int main() {
	int H1, H2, m1, m2, s1, s2;
	scanf("%d:%d:%d", &H1, &m1, &s1);
	scanf("%d:%d:%d", &H2, &m2, &s2);
	if (s1 > s2) {
		s2 += 60;
		m2--;
	}
	if (m1 > m2) {
		m2 += 60;
		H2--;
	}
	if (H1 > H2)
		H2 += 24;
	if (H2-H1 < 10)
		printf("0");
	printf("%d:", H2 - H1);
	if (m2 - m1 < 10)
		printf("0");
	printf("%d:", m2 - m1);
	if (s2 - s1 < 10)
		printf("0");
	printf("%d\n", s2 - s1);
	return 0;
}