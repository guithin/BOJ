#include <stdio.h>
#include <algorithm>
using namespace std;

#define MIN(a, b)	(a < b ? (a) : (b))
#define ABS(x)		(x < 0 ? (-(x)) : (x))

int main()
{
	int N, n[5000]; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &n[i]);

	sort(n, n + N);

	long long int min = 3000000001, sum;
	int ans1, ans2, ans3;
	for (int i = 0, k, im = N - 2; (i < im) && min; i++){
		for (int j = i + 1, k = N - 1, jm = N - 1; j < jm; j++){
			for (k = MIN(k, N - 1); k > j; k--){
				sum = (long long)n[i] + n[j] + n[k];
				if (ABS(sum) < min){
					min = ABS(sum);
					ans1 = n[i]; ans2 = n[j]; ans3 = n[k];
				}
				if (sum < 0){ k++; break; }
			}
		}
	}

	printf("%d %d %d\n", ans1, ans2, ans3);
	return 0;
}