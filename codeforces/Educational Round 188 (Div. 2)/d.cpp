#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n);
    vector<int> color(n);

    auto bfs = [&](auto rc, int u) -> pair<int, int>
    {
        queue<int> q;
        q.push(u);
        color[u] = 1;
        vis[u] = true;
        int quant = 1, a = 1;

        bool is_bipartite = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v : adj[u])
            {
                if(color[v] == color[u])
                {
                    is_bipartite = false;
                    continue;
                }

                if(vis[v]) continue;

                q.push(v);
                vis[v] = true;
                if(color[u] == 2)
                {
                    color[v] = 1;
                    a++;
                }
                else color[v] = 2;
                quant++;
            }
        }

        if(!is_bipartite) return {0, 0};
        return {quant, a};
    };

    int ans = 0;
    for(int u = 0; u < n; u++)
    {
        if(vis[u]) continue;

        pair<int, int> rtrn = bfs(bfs, u);
        auto [quant, a] = rtrn;
        if(quant == 0) continue;
        ans += max(a, quant-a);
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
