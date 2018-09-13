#include<stdio.h>
#include<string.h>

int main(){
	char input[110] = { 0 };
	int map[101][101] = { 0 };
	scanf("%s", input);
	int len = strlen(input);
	int max = 0;
	for (int i = 1; i*i <= len; i++){
		if (len%i == 0)
			max = i;
	}
	int idx = 0;
	for (int i = 1; i <= len/max; i++){
		for (int j = 1; j <= max; j++){
			map[i][j] = input[idx];
			idx++;
		}
	}
	idx = 0;
	for (int j = 1; j <= max; j++){
		for (int i = 1; i <= len/max; i++){
			input[idx] = map[j][i];
			printf("%c", map[i][j]);
			idx++;
		}
	}
	printf("\n");
//	printf("%s\n", input);
	return 0;
}