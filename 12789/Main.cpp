#include<stdio.h>


int main(){
	int n;
	int input[1010] = { 0 };
	bool check[1010] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &input[i]);
	}
	for (int i = n; i >= 1; i--	){
		if (i == n){
			check[input[i]] = true;
			continue;
		}
		if (input[i + 1]+1 < input[i]){
			bool flag = false;
			for (int j = input[i + 1] + 1; j < input[i]; j++){
				if (check[j] == false){
					flag = true;
					break;
				}
			}
			if (flag == true){
				printf("Sad\n");
				return 0;
			}
		}
		check[input[i]] = true;
	}
	printf("Nice\n");
	return 0;
}