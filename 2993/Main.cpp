#include<stdio.h>
#include<string.h>

char input[60] = { 0 };
char temp[60] = { 0 };
char match[60] = { 0 };
int idx1 = 0;
int idx2 = 1;
int len;

bool check(int idx1, int idx2){
	int index = 0;
	for (int i = idx1; i >= 0; i--){
		temp[index] = input[i];
		index++;
	}
	for (int i = idx2; i >= idx1 + 1; i--){
		temp[index] = input[i];
		index++;
	}
	for (int i = len - 1; i >= idx2 + 1; i--){
		temp[index] = input[i];
		index++;
	}
//	printf("%d %d\n", idx1, idx2);
//	printf("%s\n", temp);
	if (strncmp(match, temp, len) > 0)
		return true;
	else return false;
}

int main(){
	scanf("%s", input);
	len=strlen(input);
	for (int i = 0; i < len; i++){
		match[i] = input[i];
	}
	int ansi = 0, ansj = 1;
	for (int i = 0; i < len - 2; i++){
		for (int j = i + 1; j < len - 1; j++){
			if (check(i, j) == true){
//				printf("%d %d\n", i, j);
				for (int k = 0; k < len; k++){
					match[k] = temp[k];
				}
			}
		}
	}
	printf("%s\n", match);
	return 0;
}