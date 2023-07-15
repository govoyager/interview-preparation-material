#include <bits/stdc++.h>

using namespace std;

int main(){

    string s,res = "";
    cin>>s;
    int n = s.length();
    if(s[n-1] >= '0' && s[n-1] <= '9'){
        for(int i=0;i<n;i++){
            if(i == n-1){
                res += s[i]+1;
            }
            else
            res += s[i];
        }
    }
    else{
        cout<<s+"1";
    }
    cout<<res;



}