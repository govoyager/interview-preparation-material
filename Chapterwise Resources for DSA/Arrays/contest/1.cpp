#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,d,m;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>d>>m;
    int sum = 0;
    int l;
    for (int i=0; i<n; i++)
    {   
        int temp_sum = 0;
        if((i+m)>n) 
        {
            cout<<sum;
            return;
        }
        for(int j=0; j<m; j++)
        {
            temp_sum = temp_sum+ arr[i+j];     
        }
        if(temp_sum==d)
        {
            sum++;
        }
        
    }
    cout<<sum;
}