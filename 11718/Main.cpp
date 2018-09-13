#include<stdio.h>
int main(){
    while(1){
        char c=getchar();
        if(c<0)return 0;
        printf("%c",c);
    }
}