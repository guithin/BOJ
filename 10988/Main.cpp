#include<bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	for (int i = s1.size() - 1; i + 1; i--) s2 += s1[i];
	printf("%d\n", s1 == s2);
	return 0;
}