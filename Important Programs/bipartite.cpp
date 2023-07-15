#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
vector<int> graph[N];
int level[N];
bool vis[N];

bool bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    level[s] = 0;
    while (!q.empty())
    {
        int e = q.front();
        q.pop();
        for (auto i : graph[e])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push(i);
                level[i] = level[e] + 1;
            }
            else if (level[e] == level[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, e, u, v;
    cin >> v >> e;
    while (e--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        // Comment this line for a directed graph.
        graph[v].push_back(u);
    }
    int source = 1;
    if (bfs(source))
        cout << "The graph is bipartite";
    else
        cout << "The graph is not bipartite";
}