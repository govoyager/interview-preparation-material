#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[10] = {9, 6, 7, 8, 3, 4, 5, 1, 0, 2};
    insertionSort(arr, 10);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}