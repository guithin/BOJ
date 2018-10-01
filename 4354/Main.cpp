#include<bits/stdc++.h>
using namespace std;

int len;
char str[1000010];
vector<int>vec;

bool func(int x) {
	for (int i = 0; i < len; i += x) {
		if (strncmp(str, str + i, x))return false;
	}
	return true;
}

int main() {
	while (1) {
		vec.clear();
		memset(str, 0, sizeof(str));
		scanf("%s", str);
		if (str[0] == '.')break;
		len = strlen(str);
		for (int i = 1; i*i <= len; i++) {
			if (!(len%i)) {
				if (i*i == len) vec.push_back(i);
				else {
					vec.push_back(i); vec.push_back(len / i);
				}
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			if (func(vec[i])) {
				printf("%d\n", len / vec[i]);
				break;
			}
		}
	}
	return 0;
}