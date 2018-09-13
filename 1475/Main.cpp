#include<bits/stdc++.h>
using namespace std;

char str[100010];
int s[10];

int main() {
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		s[str[i] - '0']++;
	}
	int maxi = (s[9] + s[6] + 1) / 2;
	s[6] = 0;
	for (int i = 0; i < 9; i++) {
		maxi = max(maxi, s[i]);
	}
	printf("%d\n", maxi);
	return 0;
}