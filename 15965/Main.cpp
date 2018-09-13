#include<stdio.h>
#include<vector>
using namespace std;

#define MAXI 7368787

bool sosu[MAXI];
vector<int>vec;

int main() {
	sosu[0] = sosu[1] = 1;
	for (int i = 2; i <= MAXI; i++) {
		if (sosu[i])continue;
		for (int j = 2; i*j <= MAXI; j++) {
			sosu[i*j] = 1;
		}
	}
	for (int i = 1; i <= MAXI; i++) {
		if (!sosu[i])vec.push_back(i);
	}
	int k;
	scanf("%d", &k);
	printf("%d\n", vec[k - 1]);
	return 0;
}