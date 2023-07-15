#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,t,count=0;
    vector<long long int> v;
    cin>>n>>t;
    long long int task=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i] + task <= t){
            task += v[i];
            count +=1; 
        }
        else{
            break;
        }
    }
    //cout<<count<<" "<<v.size()<<" ";

    if(count == 0)
    {
        cout<<0;
        return 0;
    }
    cout<<(count*5)-((int)v.size()-count);
}