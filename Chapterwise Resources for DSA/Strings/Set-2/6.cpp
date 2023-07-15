#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    int rows = numRows;
    string ans = "";
    vector<string> zigzag(rows);
    int rowNumber = 0;
    int change = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (rowNumber == rows)
        {
            rowNumber -= 2;
            change = -1;
        }
        if (rowNumber == -1)
        {
            rowNumber += 2;
            change = 1;
        }
        //cout<<rowNumber<<endl;
        zigzag[rowNumber].push_back(s[i]);
        rowNumber += change;
    }
    for (int i = 0; i < rows; i++)
    {
        ans += zigzag[i];
        //cout<<zigzag[i]<<endl;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << convert(s, n);
}