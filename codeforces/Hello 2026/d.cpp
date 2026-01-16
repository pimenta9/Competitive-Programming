#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1 + size(adj[0]);
    for(int u = 1; u < n; u++)
    {
        ans = max(ans, (long long)adj[u].size());
    }

    vector<int> dist(n);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(v == 0 or dist[v] != 0) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << dist[i] << ' ';
    // }
    // cout << '\n';

    vector<int> quant_dist(n);
    for(int u = 0; u < n; u++)
    {
        quant_dist[dist[u]]++;
    }

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, quant_dist[i]);
    }

    cout << ans << "\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
