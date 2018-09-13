#include<stdio.h>
#include<algorithm>
int main(){
    int n=9;
    int inp[10]={};
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d", inp+i);
        sum+=inp[i];
    }
    std::sort(inp+1, inp+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(sum==inp[i]+inp[j]+100){
                for(int k=1;k<=n;k++){
                    if(k==i||k==j)continue;
                    printf("%d ", inp[k]);
                }
                return 0;
            }
        }
    }
    return 0;
}