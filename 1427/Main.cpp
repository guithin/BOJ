#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10]={};
    while(1){
        char c=getchar();
        if(c==EOF)break;
        arr[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(arr[i]--)printf("%d", i);
    }
    return 0;
}