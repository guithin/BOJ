#include<stdio.h>

int main(){
    long long n=0;
    int l;
    scanf("%d", &l);
    for(int i=1;i<=l;i++){
        int temp;
        scanf("%1d", &temp);
        n+=temp;
    }
    printf("%lld\n", n);
}