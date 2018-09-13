#include<stdio.h>

int main(){
	int input[10] = { 0 };
	bool as = true;
	bool de = true;
	for (int i = 1; i <= 8; i++){
		scanf("%d", &input[i]);
		if (i == 1){
			if (input[i] == 1)de = false;
			if (input[i] == 8)as = false;
		}
		else{
			if (input[i - 1] + 1 != input[i])as = false;
			if (input[i - 1] - 1 != input[i])de = false;
		}
	}
	if (as == true){
		printf("ascending\n");
		return 0;
	}
	if (de == true){
		printf("descending\n");
		return 0;
	}
	printf("mixed\n");
	return 0;
}