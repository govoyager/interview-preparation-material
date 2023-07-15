#include<bits/stdc++.h>
using namespace std;


int minFlips (string S)
{
    // your code here
    int n = S.length();
    char a = '0';
    int count1 = 0 , count2 = 0;
    for(int i = 0; i<n;i++){
        if(S[i] != a)
        count1 += 1;
        a=='0'?a='1':a='0';
    }
    a = '1';
    for(int i = 0; i<n;i++){
        if(S[i] != a)
        count2 += 1;
        a=='0'?a='1':a='0';
    }
    return min(count1,count2);
}

int main(){
    cout<<minFlips("1110001010101100");
}