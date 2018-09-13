#include<stdio.h>

bool chk[2000010];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d", &temp);
        chk[temp+1000000]=true;
    }
    for(int i=2000000;i>=0;i--){
        if(chk[i]){
            printf("%d\n", i-1000000);
        }
    }
    return 0;
}