/* This program works for positive and negative numbers both and doest give duplicate pairs also.*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    unordered_map<int,int> m;
    
    cin>>n>>k;
    vector<int> arr;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a,arr.push_back(a);
    }
    //The following three lines of code is to remove the duplicates 
    //from the input so that the output also wont be having duplicate pairs
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(m.find(k+arr[i]) == m.end() &&  m.find(arr[i]-k) == m.end() )
        {
            m[arr[i]]=i;
        }
        else
        {
            if(m.find(k+arr[i]) != m.end())
            {
                cout<<"("<<k+arr[i]<<","<<arr[i]<<")"<<endl;
                m[arr[i]]=i;
            }
            else
            {
                cout<<"("<<-k+arr[i]<<","<<arr[i]<<")"<<endl;
                m[arr[i]]=i;
            }
            
        }
        
    }

}