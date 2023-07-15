#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,r;
        cin>>a>>b>>c;
        r = a+b+c - 2*((a+b+c)/7);
        
        if(r%7){
            cout<<"NO\n";
        }
        else
        {
            if(min({a,b,c}) >= ((a+b+c)-min({a,b,c}))/7 )
            {
            cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
            
        }
        


    }
}