#include<stdio.h>

int main(){
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if(a-b>0)printf("%lld\n", a-b);
    else printf("%lld\n", b-a);
    return 0;
}