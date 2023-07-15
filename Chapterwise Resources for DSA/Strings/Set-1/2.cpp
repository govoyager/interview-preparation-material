#include<bits/stdc++.h>
using namespace std;

int isPlaindrome(char S[])
{
    // Your code goes here
    int n = strlen(S);
    int flag = 1;
    for(int i =0;i<n;i++){
        if(S[i] != S[n-1-i]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    cout<<isPlaindrome("abba")<<endl;
    cout<<isPlaindrome("abbccbba")<<endl;
    cout<<isPlaindrome("geeks")<<endl;
    return 0;
}