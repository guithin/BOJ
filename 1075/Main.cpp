#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b; scanf("%d %d", &a, &b);
	a = a / 100 * 100;
	while (a%b)a++;
	printf("%02d\n", a % 100);
	return 0;
}