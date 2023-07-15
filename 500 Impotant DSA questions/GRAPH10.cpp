#include <bits/stdc++.h>
using namespace std;
#define N 100
const int n = 1e6 + 3;
vector<int> graph[n];
bool vis[n];
int level[n];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int e;
        e = q.front();
        q.pop();
        if (e == N)
        {
            cout << level[e];
        }
        for (auto i : graph[e])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
                level[i] = level[e] + 1;
            }
        }
    }
}

int main()
{
    unordered_map<int, int> ladder, snake;

    // insert ladders into the map
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;

    // insert snakes into the map
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 6 && i + j <= N; j++)
        {
            int dest = (snake[i + j] || ladder[i + j]) ? (snake[i + j] + ladder[i + j]) : (i + j);
            graph[i].push_back(dest);
        }
    }
    bfs(0);
}