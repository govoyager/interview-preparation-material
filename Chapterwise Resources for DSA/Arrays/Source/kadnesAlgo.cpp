#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int local_maximum = 0, global_maximum = 0;
    for (int i = 1; i < n; i++)
    {
        local_maximum = max(local_maximum + arr[i], arr[i]);
        global_maximum = max(global_maximum, local_maximum);
    }
    cout << (global_maximum <= 0 ? 0 : global_maximum);
}