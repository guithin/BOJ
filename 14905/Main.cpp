#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>vec;
bool p[100000001] = {};

int main() {
	p[0] = p[1] = true;
	for (long long i = 2ll; i <= 100000000ll; i++) {
		if (p[i])continue;
		for (long long j = i; j*i <= 100000000ll; j++) {
			p[i*j] = true;
		}
	}
	for (int i = 2; i <= 100000000; i++) {
		if (!p[i])vec.push_back(i);
	}
	int n;
	while (scanf("%d", &n) > 0) {
		if (n < 8) {
			printf("Impossible.\n");
			continue;
		}
		int temp = lower_bound(vec.begin(), vec.end(), n - 6) - vec.begin();
		if (temp == vec.size() || vec[temp] != n - 6)temp--;
		printf("%d ", vec[temp]);
		n -= vec[temp];
		temp = lower_bound(vec.begin(), vec.end(), n - 4) - vec.begin();
		if (temp == vec.size() || vec[temp] != n - 4)temp--;
		printf("%d ", vec[temp]);
		n -= vec[temp];
		temp = lower_bound(vec.begin(), vec.end(), n - 2) - vec.begin();
		if (temp == vec.size() || vec[temp] != n - 2)temp--;
		printf("%d %d\n", vec[temp], n - vec[temp]);
	}
	return 0;
}