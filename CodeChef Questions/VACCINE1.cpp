#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d1,v1,d2,v2,p,day=1;
    cin>>d1>>v1>>d2>>v2>>p;
    while(p>0)
    {
        if(day < min({d1,d2}))
        {
            day = day +1;
        }
        else if(day<max({d1,d2}) && day >=  min({d1,d2}))
        {
            day = day +1;
            p = p - (d1 == min({d1,d2})?v1:v2);

        }
        else if(day>= max({d1,d2}))
        {
            day = day +1;
            p = p- (v1+v2);
        }
        
        

    }
    cout<<day-1;
    
}