#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string S)
{
    // code here.
    string str = "";
    str.push_back(S[0]);
    char last_read = S[0];
    for (int i = 1; i < S.length(); i++)
    {
        if (last_read != S[i])
        {
            str.push_back(S[i]);
            last_read = S[i];
        }
    }
    return str;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << removeConsecutiveCharacter(s) << endl;
    }
}