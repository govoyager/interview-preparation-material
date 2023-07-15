#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m;
    cin>>n>>m;
    vector<int> arr;
    for(int i=0;i<=n;i++){
        arr.push_back(0);
    }
    for(int i = 0;i<m;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        arr[a-1] += c;
        if(b<n)
        arr[b] -= c;
    }
    long long int maxi = -1;
    long long int val = 0;
    for(int i=0;i<n;i++){
        val += arr[i];
        if(val > maxi)
            maxi = val;
    }
    cout<<maxi;
}
