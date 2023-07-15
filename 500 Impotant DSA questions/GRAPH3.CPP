#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
vector<int> graph[N];
bool vis[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int e = q.front();
        q.pop();
        for(auto i:graph[e] ){
            if(!vis[i])
            {
                vis[i] = true;
                q.push(i);
            }
        }
    }
    
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
    int source, dest;
    cin >> source >> dest;
    bfs(source);
    if (vis[dest])
        cout << "Path exists";
    else
    {
        cout << "Path does not exist";
    }
}