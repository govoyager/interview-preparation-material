#include <bits/stdc++.h>
using namespace std;

string trim(string str)
{
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start))
    {
        start++;
    }
    auto end = str.end();
    do
    {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return string(start, end + 1);
}

int main()
{
    string str;
    //scanf("%[^\n]%*c",str);
    //gets(str);
    getline(cin, str);
    str = trim(str);
    cout << str;
}