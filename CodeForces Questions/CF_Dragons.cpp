#include <bits/stdc++.h> 

using namespace std;

int main(){
    int s,n;
    cin>>s>>n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(s <= v[i].first){
            cout<<"NO";
            return 0;
        }
        else
        {
            s = s+ v[i].second;
        }
        
    }
    cout<<"YES";
    return 0;
    
}