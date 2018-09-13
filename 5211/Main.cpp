#include<stdio.h>
#include<string.h>

int main() {
	char str[110] = { 0 };
	scanf("%s", str);
	int da = 0;
	int ga = 0;
	int len = strlen(str)-1;
	for (int i = 0; str[i] != 0; i++) {
		if (i == 0) {
			if (str[i] == 'A' || str[i] == 'D' || str[i] == 'E')
				ga++;
			else if (str[i] == 'C' || str[i] == 'F' || str[i] == 'G')
				da++;
		}
		if (str[i] == '|') {
			if (str[i + 1] == 'A' || str[i + 1] == 'D' || str[i + 1] == 'E')
				ga++;
			else if (str[i + 1] == 'C' || str[i + 1] == 'F' || str[i + 1] == 'G')
				da++;
		}
	}
	if (ga > da)
		printf("A-minor\n");
	else if(ga<da)
		printf("C-major\n");
	else {
		if(str[len]=='A'||str[len]=='D'||str[len]=='E')
			printf("A-minor\n");
		else
			printf("C-major\n");
	}

	return 0;
}