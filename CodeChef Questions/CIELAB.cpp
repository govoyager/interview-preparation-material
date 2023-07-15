#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b;
    c = a-b;
    if(c%10 == 0)
     {
        cout<<c+1;
     }

    else if ((c+1)%10 == 0)
    {
        cout<<c-1;
    }
    else 
    {
        cout<<c+1;
    }
    return(0);
}