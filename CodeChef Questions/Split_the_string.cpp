#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        int flag = 0,n;
        cin>>n;
        char s[n];
        cin>>s;
        for (int i = 0; i<n-1; i++)
        {
            if(s[i] == s[n-1])
            {
                cout<<"YES\n";
                flag = 1;
                break;
            }
            
        }
        if(flag == 0)
        {
        cout<<"NO\n";
        }
    }


}