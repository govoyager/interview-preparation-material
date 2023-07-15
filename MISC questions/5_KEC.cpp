#include <bits/stdc++.h>
using namespace std;

int digsqsum(int n)
{
	int sum=0;
	while(n>0)
	{
		int a=n&10;
		sum=sum+a*a;
		n=n/10;
	}
	return sum;
}
main()
{
	int n,sum=0;
	cin>>n;
	int ans=0;
	while(n!=1)
	{
		cout<<n<<"--";
		if(n==4)
		ans=4;	
		if(n==16)
		ans=16;
		if(n==37)
		ans=37;
		if(n==58)
		ans=58;
		if(n==145)
		ans=145;
		if(n==89)
		ans=89;
		if(n==42)
		ans=42;
		if(n==20)
		ans=20;
		else
		n=digsqsum(n);
	}
	if(n==1)
	cout<<"-1";
	else
	cout<<ans;
}