#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>

struct pos {
	int x;
	int y;
};

pos input[30];
int permu[30] = { 0 };

long long abb(long long x) {
	return x > 0 ? x : -x;
}

int main() {
	long long t;
	scanf("%lld", &t);
	while (t--) {
		long long n;
		memset(permu, 0, sizeof(permu));
		scanf("%lld", &n);
		for (long long i = 1; i <= n; i++) {
			scanf("%lld %lld", &input[i].x, &input[i].y);
			if (i > n / 2)permu[i] = 1;
		}
		double mini = 987654321;
		long long qwer = 0;
		long long asdf = 0;
		for (long long i = 1; i <= n; i++) {
			if (permu[i]==1) {
				qwer += input[i].x;
				asdf += input[i].y;
			}
			else {
				qwer -= input[i].x;
				asdf -= input[i].y;
			}
		}
		double ssss = sqrt((double)abb(qwer*qwer) + (double)abb(asdf*asdf));
		if (ssss < mini)mini = ssss;
		while(std::next_permutation(permu+1, permu+1+n)){
			long long xx = 0;
			long long yy = 0;
			for (long long i = 1; i <= n; i++) {
				if (permu[i]==1) {
					xx += input[i].x;
					yy += input[i].y;
				}
				else {
					xx -= input[i].x;
					yy -= input[i].y;
				}
			}
			double temp = sqrt((double)abb(xx*xx) + abb(yy*yy));
			if (temp < mini)mini = temp;
		}
		printf("%.6lf\n", mini+1e-9);
	}
	return 0;
}