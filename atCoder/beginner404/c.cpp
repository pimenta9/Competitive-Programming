#include <bits/stdc++.h>
using namespace std;

bool all_reachable(vector<vector<int>> g)
{
    vector<bool> seen(g.size(), false);

    queue<int> q;
    q.push(1);
    seen[1] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : g[u])
        {
            if (!seen[v])
            {
                seen[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 1; i < seen.size(); i++)
        if (seen[i] == false) return false;
    return true;
}

int main ()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if (n != m)
    {
        cout << "No\n";
        return 0;
    }

    vector<vector<int>> g(n+1);
    vector<int> degree(n+1, 0);
    for (auto [u, v] : edges)
    {
        degree[u]++;
        degree[v]++;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if (degree[i] != 2)
        {
            cout << "No\n";
            return 0;
        }

    if (!all_reachable(g))
    {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    return 0;
}
