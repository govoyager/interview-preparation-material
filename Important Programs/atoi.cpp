#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    long long int result = 0;
    int i = 0;
    int sign = 1;
    while (str[i] == ' ')
        i++;
    if (str[i] == '+')
    {
        sign = 1;
        i++;
    }
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        int num = str[i] - '0';
        result = (result * 10) + num;
        i++;
        if (result >= INT_MAX)
        {
            if (sign == 1)
                return INT_MAX;
            else
            {
                return INT_MIN;
            }
        }
    }
    return sign * result;
}

int main()
{
    string s;
    getline(cin, s);
    int result = atoi(s);
    cout << result;
}