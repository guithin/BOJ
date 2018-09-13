#include<stdio.h>

int n, m;
int inp[50]={0};
int qwer[30010]={0};
int asdf[30010]={0};

void back(int cur, int sum){
	if(cur==n/2){
		qwer[sum+15000]=1;
		return;
	}
	back(cur+1, sum);
	back(cur+1, sum+inp[cur+1]);
	back(cur+1, sum-inp[cur+1]);
}

void back2(int cur, int sum){
	if(cur==n){
		asdf[sum+15000]=1;
		return;
	}
	back2(cur+1, sum);
	back2(cur+1, sum+inp[cur+1]);
	back2(cur+1, sum-inp[cur+1]);
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", inp+i);
	back(0, 0);
	back2(n/2, 0);
//	printf("ssd\n");
	scanf("%d", &m);
	for(int i=1;i<=m;i++){
		int temp;
		bool flag=false;
		scanf("%d", &temp);
		for(int j=0;j<=30000;j++){
			if(qwer[j]&&((j+temp<=30000&&asdf[j+temp])||(j>=temp&&asdf[j-temp]))){
				printf("Y ");
				flag=true;
				break;
			}
		}
		if(flag)continue;
		printf("N ");
	}
	printf("\n");
	return 0;
}