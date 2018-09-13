#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int map[110][110]={};
    bool chk[10010]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &map[i][j]);
            if(chk[map[i][j]]){
                printf("FALSE\n");return 0;
            }
            chk[map[i][j]]=true;
        }
    }
    for(int i=1;i<=n*n;i++){
        if(!chk[i]){
            printf("FALSE\n");
            return 0;
        }
    }
    int temp=0;
    for(int i=1;i<=n;i++){
        temp+=map[1][i];
    }
    for(int i=1;i<=n;i++){
        int a=0;
        for(int j=1;j<=n;j++){
            a+=map[i][j];
        }
        if(a!=temp){
            printf("FALSE\n");return 0;
        }
        a=0;
        for(int j=1;j<=n;j++){
            a+=map[j][i];
        }
        if(a!=temp){
            printf("FALSE\n");return 0;
        }
    }
        int a=0,b=0;
    for(int i=1;i<=n;i++){
        a+=map[i][i];
        b+=map[n-i+1][i];
    }
    if(a!=temp)printf("FALSE\n");
    else if(b!=temp)printf("FALSE\n");
    else printf("TRUE\n");
    return 0;
}