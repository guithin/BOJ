#include<stdio.h>

int main(){
    int arr[2000010]={};
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d", &temp);
        arr[temp+1000000]++;
    }
    for(int i=0;i<=2000000;i++){
        while(arr[i]--)printf("%d\n", i-1000000);
    }
    return 0;
}