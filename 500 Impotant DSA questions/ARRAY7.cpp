#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum = 0,len=0,endindex=-1;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];
    unordered_map<int,int> m;
    m[0] = -1;
    for(int i=0;i<n;i++)
    {
        sum += (arr[i] == 0)? -1 : 1;
        if(m.find(sum) == m.end())
        {
            m[sum]=i;
        }
        else
        {
            if(len<i - m[sum])
            {
                len = i - m[sum];
                endindex = i;
            }
        }
    }
    cout<<"["<<endindex-len+2<<","<<endindex+1<<"]";

}