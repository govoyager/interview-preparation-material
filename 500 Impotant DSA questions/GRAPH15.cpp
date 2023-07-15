#include <bits/stdc++.h>
using namespace std;
const int n = 10e6 + 3;
vector<int> graph[n];
int count1;

struct node
{
    int v;
    int level;
};

void modifiedBfs(int s, int dest, int l)
{
    queue<node> q;
    node source;
    source.level = 0;
    source.v = s;
    q.push(source);
    while (!q.empty())
    {
        node v;
        v = q.front();
        q.pop();
        for (auto i : graph[v.v])
        {
            if (v.level < l)
            {
                source.v = i;
                source.level = v.level + 1;
                if (source.level == l && i == dest)
                    count1 += 1;
            }
            q.push(source);
        }
    }
}

int main()
{
    int N, m, u, v, l, dest, source;
    cin >> N >> m >> source >> dest >> l;
    while (m--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    modifiedBfs(source, dest, l);
    cout << count1;
}