#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n-(n&-n)?0:1);
    return 0;
}