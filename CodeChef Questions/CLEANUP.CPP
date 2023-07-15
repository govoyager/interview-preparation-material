#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t!=0){
		int n,m;
		cin>>n>>m;
		int a[m],ar[n];
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			ar[i]=i+1;
		}
		for(int i=0;i<m;i++){
			ar[a[i]-1]=-1;
		}
		int c[n],ast[n],j=0,flag=0,c1=0,c2=0;
		for(int i=0;i<n;i++){
			if (ar[i]!=-1){
				if(flag==0){
					c[j]=ar[i];
					flag=1;
					c1+=1;
					continue;
				}
				else{
					ast[j]=ar[i];
					flag=0;
					c2+=1;
					j+=1;
				}
			}
		}
		for(int i=0;i<c1;i++){
			cout<<c[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<c2;i++){
			cout<<ast[i]<<" ";
		}
		cout<<endl;
		t--;
	}
}
