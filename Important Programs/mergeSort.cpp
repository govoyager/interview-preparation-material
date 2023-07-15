#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	// 2 3 4
	// l m r --> l m  || m+1 r
	//	l = 2 r = 4
	//  m = 3
	//  first array size = m+1-l second array size = (r+1) - (m+1)==> r-m;
	int n1 = m + 1 - l;
	int n2 = r - m;
	int arr1[n1], arr2[n2];

	cout<<"FIRST SUB ARRAY: ";
	for (int i = 0; i < n1; i++)
	{
		arr1[i] = arr[i + l];
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
	cout<<"SECOND SUB ARRAY: ";
	for (int i = 0; i < n2; i++)
	{
		arr2[i] = arr[i + m + 1];
		cout<<arr2[i]<<" ";
	}

	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 and j < n2)
	{
		if (arr1[i] > arr2[j])
		{
			arr[k] = arr2[j];
			j = j+1;
		}
		else
		{
			arr[k] = arr1[i];
			i+= 1;
		}
		k+=1;
	}

	while (i < n1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
	cout<<endl<<"MAIN ARRAY: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout<<endl;
	cout<<endl;
}

void mergeSort(int arr[], int l, int r)
{
	if(r<=l){
		return;
	}
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}