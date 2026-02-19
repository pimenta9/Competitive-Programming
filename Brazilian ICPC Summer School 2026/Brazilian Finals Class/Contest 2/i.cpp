#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

const int oo = 1e18;

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, t;
    cin >> n >> t;

    vector<vector<pii>> adj(n);

    for(int i = 0; i < t; i++)
    {
        int m; cin >> m;
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }

    int k; cin >> k;
    vector<int> a(k);
    for(int& x : a) cin >> x;

    vector<map<int, bool>> mps(t);
    for(int i = 0; i < k; i++)
        mps[a[i]-1][i] = true;

    // for(int i = 0; i < t; i++)
    // {
    //     cout << i << ":\n";
    //     for(auto [k, v] : mps[i])
    //         cout << k << ' ';
    //     cout << '\n';
    // }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> vis(n);
    vector<int> dist(n);
    pq.emplace(-1, 0);

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        
        if(vis[u]) continue;
        vis[u] = true;
        dist[u] = d;
        d++;

        for(auto [v, time] : adj[u])
        {
            auto next_it = mps[time].lower_bound(d);
            if(next_it == mps[time].end()) continue;
            int next_d = next_it->first;
            pq.emplace(next_d, v);
        }
    }

    // for(int i = 0; i < n; i++)
    //     cout << dist[i] << '\n';

    if(vis[n-1])
        cout << dist[n-1]+1 << '\n';
    else
        cout << "-1\n";

    return 0;
}
