#include<stdio.h>
#include<algorithm>
using namespace std;

bool check[110] = { 0 };
int n, m;
char pick[110] = { 0 };
char input[20] = { 0 };

void back(int cur, int idx) {
	if (cur == n + 1) {
		int ja=0;
		int mo=0;
		for (int i = 1; i <= n; i++) {
			if (pick[i] == 'a' || pick[i] == 'e' || pick[i] == 'i' || pick[i] == 'o' || pick[i] == 'u')
				mo++;
			else
				ja++;
		}
		if (mo < 1 || ja < 2)
			return;
		for (int i = 1; i <= n; i++) {
			printf("%c", pick[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i <= m; i++) {
		if (check[i] == true)continue;
		pick[cur] = input[i];
		check[i] = true;
		back(cur + 1, i);
		check[i] = false;
		pick[cur] = 0;
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf(" %c", &input[i]);
	}	
	sort(input + 1, input + 1 + m);
	back(1,1);
	return 0;
}