#include<bits/stdc++.h>
using namespace std;

int main(){
    int k[3];scanf("%d %d %d", k, k+1, k+2);
    sort(k, k+3);
    for(int i=0;i<3;i++){
        char c;scanf(" %c", &c);
        printf("%d ", k[c-'A']);
    }printf("\n");
    return 0;
}