#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = n - 2; i >= 0; i--)
    {
        swapped = false;
        for (j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

int main()
{
    int arr[10] = {3, 4, 2, 1, 7, 8, 0, 9, 5, 6};
    bubbleSort(arr, 10);
    for (int i : arr)
    {
        cout << i << " ";
    }
}