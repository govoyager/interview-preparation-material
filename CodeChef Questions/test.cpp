#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[(int)1e5];
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    set<pair<int,int> > s;
    int x = 1;
    for(int i = 1 ; i < n ; i++){
        if(a[i] == a[i-1]) x++;
        else{
            s.insert(make_pair(x,a[i-1]));
            x = 0;
        }
    }
    for(auto i : s){
        cout << i.second << " ";
    }
}