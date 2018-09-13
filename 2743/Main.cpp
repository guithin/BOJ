#include<stdio.h>
#include<string.h>
int main(){
    char str[100000]={0};
    scanf("%s", str);
    printf("%d\n", strlen(str));
    return 0;
}