#include<stdio.h>
#include<algorithm>
int main(){
    int n;
    scanf("%d", &n);
    int inp[1010];
    for(int i=1;i<=n;i++)scanf("%d", inp+i);
    std::sort(inp+1, inp+1+n);
    for(int i=1;i<=n;i++)printf("%d\n", inp[i]);
    return 0;
}