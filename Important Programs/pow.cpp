#include<bits/stdc++.h>
using namespace std;

int binaryPow(int x, int n){
    if(x == 0 or x == 1){
        return x;
    }
    int ans=1;
    while(n>0){
        if(n%2)
        ans = ans * x;
        n = n/2;
        x = x*x;
    }
    return ans;
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<binaryPow(x,n);
}