#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    long long fibo[110]={0,1,1};
    for(int i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    printf("%lld\n", fibo[n]);
    return 0;
}