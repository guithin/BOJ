#include<stdio.h>

int main(){
	int p[15] = { 0 };
	int k[15] = { 0 };
	int h[15] = { 0 };
	int t[15] = { 0 };
	char str[1010] = { 0 };
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++){
		if (str[i] == 'P'){
			if (str[i + 1] == '0'){
				p[str[i + 2] - '0']++;
			}
			else{
				p[10 + str[i + 2] - '0']++;
			}
		}
		else if (str[i] == 'K'){
			if (str[i + 1] == '0'){
				k[str[i + 2] - '0']++;
			}
			else{
				k[10 + str[i + 2] - '0']++;
			}
		}
		else if (str[i] == 'H'){
			if (str[i + 1] == '0'){
				h[str[i + 2] - '0']++;
			}
			else{
				h[10 + str[i + 2] - '0']++;
			}
		}
		else{
			if (str[i + 1] == '0'){
				t[str[i + 2] - '0']++;
			}
			else{
				t[10 + str[i + 2] - '0']++;
			}
		}
		i += 2;
	}
	int pp = 13;
	int kk = 13;
	int hh = 13;
	int tt = 13;
	for (int i = 1; i <= 13; i++){
		if (p[i] > 1 || k[i] > 1 || t[i] > 1 || h[i] > 1){
			printf("GRESKA\n");
			return 0;
		}
		if (p[i] == 1)pp--;
		if (k[i] == 1)kk--;
		if (t[i] == 1)tt--;
		if (h[i] == 1)hh--;
	}
	printf("%d %d %d %d\n", pp, kk, hh, tt);
	return 0;
}