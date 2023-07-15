#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int flag =1;
    
    for(int i=0;i<3;i++)
    {
        if(a[i] != c[2-i])
        {
            flag =0;
        }
    }
    if(flag == 0)
    cout<<"NO";
    else
    {
        if(b[0] == b[2])
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        
    }
    
    

}