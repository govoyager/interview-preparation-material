#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    for (int i = 0; i < (s.size()) / 2; i++)
    {
        swap(s[i], s[s.size() - 1 - i]);
    }
}

int main(){
    vector<char> s;
    s.push_back('r');
    s.push_back('a');
    s.push_back('g');
    s.push_back('u');
    s.push_back('l');
    reverseString(s);
    for(auto i: s){
        cout<<i;
    }
}