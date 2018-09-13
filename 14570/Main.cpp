#include<stdio.h>

struct pos{
	int left;
	int right;
	int level;
};

pos ver[200010] = { 0 };

int main(){
	ver[1].level = 1;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		pos temp;
		scanf("%d %d", &temp.left, &temp.right);
		ver[i] = temp;
		ver[temp.left].level = ver[i].level + 1;
		ver[temp.right].level = ver[i].level + 1;
	}
	long long k;
	scanf("%lld", &k);
	int i = 1;
	while (1){
		if (ver[i].left == -1 && ver[i].right == -1)break;
		if (ver[i].left != -1 && ver[i].right != -1){
			if (k % 2 == 1){
				i = ver[i].left;
				k++;
			}
			else{
				i = ver[i].right;
			}
			k /= 2;
			continue;
		}
		else if (ver[i].left == -1){
			i = ver[i].right;
		}
		else if (ver[i].right == -1){
			i = ver[i].left;
		}
	}
	printf("%d\n", i);
	return 0;
}