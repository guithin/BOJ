#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C, K, ML;
int origin[300][300], ans[300][300];
int tree[262144], treeHf = 131072;

void add(int i, int v) {
    for(int idx = i + treeHf-1; idx > 0; idx /= 2) {
//        cout<<idx<<'\n';
        tree[idx] += v;
    }
}

int get(int i = 1, int l = 1, int r = treeHf, int k = K*K/2+1){
//    cout<<i<<' '<<l<<' '<<r<<' '<<k<<' '<<tree[i*2]<<'\n';
    int m = (l+r)/2;
    if(l == r) return l;
    if(tree[i*2] >= k) return get(i*2, l, m, k);
    return get(i*2+1, m+1, r, k - tree[i*2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>R>>C>>ML>>K;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            cin>>origin[r][c];
            origin[r][c]++;
        }
    }

    for(int r = 0; r < R - K + 1; r++) {
        memset(tree, 0, sizeof tree);
        for(int _r = r; _r < r + K; _r++) for(int c = 0; c < K; c++) add(origin[_r][c], 1)/*, cout<<"add: "<<origin[_r][c]<<'\n'*/;
        for(int c = K; c < C; c++) {
//            cout<<get()<<'\n';
            ans[r][c-K] = get();
            for(int _r = r; _r < r + K; _r++) {
                add(origin[_r][c], 1),add(origin[_r][c-K], -1);
            }
        }
        ans[r][C-K] = get();
    }

    for(int r = 0; r < R-K+1; r++) {
        cout<<ans[r][0]-1;
        for(int c = 1; c < C-K+1; c++) {
            cout<<' '<<ans[r][c]-1;
        }
        cout<<'\n';
    }

    return 0;
}

/*
5 4 20 3
5 1 2 8
12 10 3 20
8 12 19 18
17 19 2 5
11 2 4 14
 */