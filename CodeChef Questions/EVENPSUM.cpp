#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long r1 = (long long)(a/2)*(b/2);
        long long r2 = (long long)((a%2==0?(a/2):(a/2 +1))*(b%2==0?(b/2):(b/2 +1)));
        cout<<r1+r2<<"\n";

    }

}