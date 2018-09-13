#include<stdio.h>

int sort[10010]={0};

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d", &temp);
        sort[temp]++;
    }
    for(int i=1;i<=10000;i++){
        while(sort[i]--)printf("%d\n", i);
    }
    return 0;
}