#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    set<char> s;
    s.insert('E');
    s.insert('Q');
    s.insert('U');
    s.insert('I');
    s.insert('N');
    s.insert('O');
    s.insert('X');
    for (int t = 0; t < T; t++)
    {
        int n, a, b;
        //debug(n);
        cin >> n >> a >> b;
        //debug(n);
        vector<string> str;
        for (int i = 0; i < n; i++)
        {
            string s1;
            cin>>s1;
            str.push_back(s1);
        }
        long long int score1 = 0, score2 = 0;
        for (int i = 0; i < n; i++)
        {
            //cout<<str[i][0]<<endl;
            if (s.find(str[i][0]) != s.end())
                score1 += a;
            else
            {
                score2 += b;
            }
        }
        if (score1 == score2)
        {
            cout << "DRAW" << endl;
            
        }
        else if (score1 > score2)
        {
            cout << "SARTHAK" << endl;
        }
        else
        {
            cout << "ANURADHA" << endl;
        }
    }
}