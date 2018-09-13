#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100010];

void b1(int node) {
	if (arr[node * 2] != -1)
		b1(arr[node * 2]);
	if (arr[node * 2 + 1] != -1)
		b1(arr[node * 2 + 1]);
	printf("%c", node + 'A' - 1);
}

void b2(int node) {
	if (arr[node * 2] != -1)
		b2(arr[node * 2]);
	printf("%c", node + 'A' - 1);
	if (arr[node * 2 + 1] != -1)
		b2(arr[node * 2 + 1]);
}

void b3(int node) {
	printf("%c", node + 'A' - 1);
	if (arr[node * 2] != -1)
		b3(arr[node * 2]);
	if (arr[node * 2 + 1] != -1)
		b3(arr[node * 2 + 1]);
}


int main() {
	scanf("%d", &n);
	memset(arr, 0xff, sizeof(arr));
	arr[1] = 0;
	for (int i = 1; i <= n; i++) {
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		a -= 'A' - 1;
		if (b >= 'A'&&b <= 'Z')
			arr[a * 2] = b - 'A' + 1;
		else
			arr[a * 2] = -1;
		if (c >= 'A'&&c <= 'Z')
			arr[a * 2 + 1] = c - 'A' + 1;
		else
			arr[a * 2 + 1] = -1;
	}
	b3(1); printf("\n");
	b2(1); printf("\n");
	b1(1); printf("\n");
	return 0;
}