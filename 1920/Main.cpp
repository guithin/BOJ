#include<bits/stdc++.h>
using namespace std;

int n, m;
set<int>st;

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int temp;scanf("%d", &temp);
        st.insert(temp);
    }
    scanf("%d", &m);
    for(int i=1;i<=m;i++){
        int temp;scanf("%d", &temp);
        printf("%d\n", st.find(temp)!=st.end());
    }
    return 0;
}