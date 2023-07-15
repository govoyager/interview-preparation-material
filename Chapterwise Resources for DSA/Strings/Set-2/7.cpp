#include <bits/stdc++.h>
using namespace std;

string ExcelColumn(int N)
{
    // Your code goes here
    string ans = "";
    int s = 0;
    while (N > 0)
    {
        int reminder = N % 26;
        if (reminder == 0)
        {
            ans.push_back('Z');
            N = N / 26 - 1;
        }
        else
        {
            ans.push_back((char)('A' + reminder - 1));
            N = N / 26;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << ExcelColumn(n);
}