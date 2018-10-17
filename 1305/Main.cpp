#include<bits/stdc++.h>
using namespace std;

int n;
char str[1000010];
int pi[1000010];

int main() {
	scanf("%d %s", &n, str); int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j]) {
			pi[i] = ++j;
		}
		else pi[i] = 0;
	}
	printf("%d\n", n - pi[n - 1]);
	return 0;
}