#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int sec = 0;
    int flag = 0;
    while(flag == 0){
        flag = 1;
        for(int i =1;i<n;i++){
            if(v[i]>v[i-1]){
                v.erase(v.begin()+i);
                flag = 0;
                n = n-1;
            }
        }
        sec += 1;
    }
    cout<<sec-1;

}