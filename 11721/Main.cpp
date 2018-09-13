#include<stdio.h>

int main(){
    char str[110]={};
    scanf("%s", str);
    for(int i=0;str[i]!=0;i++){
        if(i&&!(i%10))printf("\n");
        printf("%c", str[i]);
    }
    return 0;
}