#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    int count = 0;
    while (n > 0)
    {
        n &= (n - 1);
        count++;
    }
    cout << count;
}