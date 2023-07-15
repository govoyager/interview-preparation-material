#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cout<<"Enter n:";
    cin>>n;
    bool arr[n+1];
    memset(arr,true,sizeof(arr));
    arr[0] = false;
    arr[1] = false;
    arr[2] = true;
    arr[3] = true;

    for(int i = 2;i*i<=n;i++){
        if(arr[i]){
            for(int j=i*i;j<=n;j += i){
                arr[j] = false;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(arr[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}