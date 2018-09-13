#include<bits/stdc++.h>
using namespace std;

int a, b;
int pick[10];
bool chk[10];
void func(int cur, int now){
    if(cur==b+1){
        for(int i=1;i<=b;i++){
            printf("%d ", pick[i]);
        }
        printf("\n");
        return;
    }
    for(int i=now;i<=a;i++){
        if(!chk[i]){
            pick[cur]=i;chk[i]=true;
            func(cur+1, i+1);
            chk[i]=false;
        }
    }
}

int main(){
    scanf("%d %d", &a, &b);
    func(1, 1);
    return 0;
}