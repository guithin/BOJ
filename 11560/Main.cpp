#include<stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		long long arr[500] = { 1, 0 };
		long long plus[500] = { 0 };
		long long k, n;
		scanf("%lld %lld", &k, &n);
		int lv = 0;
		for (int i = 0; i <= k; i++){
			for (int j = 1; j <= i; j++){
				for (int m = 0; m <= lv; m++){
					plus[m + j] += arr[m];
				}
			}
			lv += i;
			for (int j = 0; j <= lv; j++){
				arr[j] += plus[j];
				plus[j] = 0;
			}
		}
		printf("%lld\n", arr[n]);
	}
	return 0;
}