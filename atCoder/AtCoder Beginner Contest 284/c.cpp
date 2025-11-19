#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs (const int& u, const vector<vector<int>>& adj, vector<bool>& visited)
{
    for (int v : adj[u])
    {
        if (visited[v]) continue;

        visited[v] = true;
        dfs(v, adj, visited);
    }
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans++;
            visited[i] = true;
            dfs(i, adj, visited);
        }
    }

    cout << ans << '\n';

    return 0;
}
