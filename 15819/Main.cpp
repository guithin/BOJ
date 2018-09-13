#include<bits/stdc++.h>
using namespace std;

vector<string>vec;

int main(){
    int n, k;
    cin>>n>>k;
    while(n--){
        string temp;
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    cout<<vec[k-1];
    return 0;
}