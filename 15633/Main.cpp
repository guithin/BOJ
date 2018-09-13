#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int sum=0;
    for(int i=1;i<=n;i++){
        if(!(n%i))sum+=i;
    }
    printf("%d\n", sum*5-24);
    return 0;
}