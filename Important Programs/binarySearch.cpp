#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int key)
{
    while (r >= l)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] > key)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    cin >> n >> key;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "position: " << binarySearch(arr, 0, n-1, key) + 1;
}