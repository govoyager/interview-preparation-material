#include <bits/stdc++.h>
using namespace std;

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    int max_duration = releaseTimes[0];
    char k = keysPressed[0];
    for (int i = 1; i < releaseTimes.size(); i++)
    {
        int time = releaseTimes[i] - releaseTimes[i - 1];
        if (time > max_duration)
        {
            k = keysPressed[i];
            max_duration = time;
        }
        else if (time == max_duration)
            if (k < keysPressed[i])
                k = keysPressed[i];
    }
    return k;
}

int main()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(29);
    v.push_back(49);
    v.push_back(50);
    string s = "cbcd";
    cout << slowestKey(v, s);
}