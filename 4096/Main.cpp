#include<stdio.h>
#include<string.h>

long long sqr(int x, int y){
	long long R = 1;
	for (int i = 1; i <= y; i++){
		R *= x;
	}
	return R;
}

int main(){
	while (1){
		char str[50] = { 0 };
		long long sum = 0;
		scanf("%s", str);
		int len = strlen(str);
		if (len == 1 && str[0] == '0')break;
		for (int i = 0; i < len; i++){
			str[i] -= '0';
		}

		for (int i = 0; i < len / 2; i++){
			if (i + 1 == len - i -1){
				if (str[i]>str[len - i - 1]){
					sum += sqr(10, i)*(str[i] - str[len - i - 1]);
					str[len - i - 1] += str[i] - str[len - i - 1];
				}
				else if (str[i]<str[len - i - 1]){
					int tempa = (str[i] + 1) * 10 + str[i] + 1;
					int tempb = str[i] * 10 + str[len - i - 1];
					int sumtemp = (tempa - tempb);
					sum += sumtemp*sqr(10, i);
					if (sumtemp == 10){
						str[i]++;
					}
					else{
						str[len - i - 1] += sumtemp-10;
						str[i]++;
					}
				}
			}
			else if (str[i]>str[len - i-1]){
				sum += sqr(10, i)*(str[i]-str[len-i-1]);
				str[len - i - 1] += str[i] - str[len - i - 1];
			}
			else if (str[i] < str[len - i-1]){
				sum += sqr(10, i)*((str[i] + 10) - str[len - i-1]);
				str[len - i - 1] += str[i] - str[len - i - 1];
				str[len - i - 2]++;
				if (str[len - i - 2] >= 10){
					str[len - i - 2] -= 10;
					str[len - i - 3]++;
				}
			}
			for (int j = len-1; j >= 0; j--){
				if (str[j] >= 10){
					str[j] -= 10;
					str[j - 1]++;
				}
			}
		}

		for (int i = 0; i < len / 2; i++){
			if (i + 1 == len - i - 1){
				if (str[i]>str[len - i - 1]){
					sum += sqr(10, i)*(str[i] - str[len - i - 1]);
					str[len - i - 1] += str[i] - str[len - i - 1];
				}
				else if (str[i]<str[len - i - 1]){
					int tempa = (str[i] + 1) * 10 + str[i] + 1;
					int tempb = str[i] * 10 + str[len - i - 1];
					int sumtemp = (tempa - tempb);
					sum += sumtemp*sqr(10, i);
					if (sumtemp == 10){
						str[i]++;
					}
					else{
						str[len - i - 1] += sumtemp - 10;
						str[i]++;
					}
				}
			}
			else if (str[i]>str[len - i - 1]){
				sum += sqr(10, i)*(str[i] - str[len - i - 1]);
				str[len - i - 1] += str[i] - str[len - i - 1];
			}
			else if (str[i] < str[len - i - 1]){
				sum += sqr(10, i)*((str[i] + 10) - str[len - i - 1]);
				str[len - i - 1] += str[i] - str[len - i - 1];
				str[len - i - 2]++;
				if (str[len - i - 2] >= 10){
					str[len - i - 2] -= 10;
					str[len - i - 3]++;
				}
			}
			for (int j = len-1; j >= 0; j--){
				if (str[j] >= 10){
					str[j] -= 10;
					str[j - 1]++;
				}
			}
		}

		printf("%lld\n", sum);
	}
	return 0;
}