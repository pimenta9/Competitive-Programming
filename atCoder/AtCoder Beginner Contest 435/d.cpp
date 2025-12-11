#include <bits/stdc++.h>
using namespace std;

#define int long long

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
        --u; --v;

        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);

    auto dfs = [&](auto rc, int u) -> void
    {
        vis[u] = true;

        for (int v : adj[u])
        {
            if(!vis[v]) rc(rc, v);
        }
    };

    int q; cin >> q;
    while(q--)
    {
        int type, v;
        cin >> type >> v;
        --v;

        if (type == 1)
        {
            if (!vis[v]) dfs(dfs, v);
        }

        if (type == 2)
        {
            cout << ( vis[v] ? "Yes" : "No" ) << '\n';
        }
    }

    return 0;
}