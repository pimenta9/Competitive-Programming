#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
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

    int ans = -1;

    vector<int> dp(n), seen(n);

    auto calc = [&](auto rc, int u) -> void
    {
        seen[u] = 1;

        vector<int> children;
        for(int v : adj[u])
            if(!seen[v])
                children.push_back(v);

        if(children.size() == 0) return;

        for(int v : children) rc(rc, v);

        int h1 = -1, h2 = -1;
        for(int v : children)
            if(dp[v] > h1) swap(h1, h2), h1 = dp[v];
            else if(dp[v] > h2) h2 = dp[v];

        if(u == 0) // root
        {
            if(children.size() >= 3)
            {
                ans = max(ans, h1 + 1);
            }
            
            if(children.size() >= 4)
            {
                ans = max(ans, h1 + h2 + 1);
            }

            if(children.size() == 2)
            {
                ans = max(ans, 1ll);
            }

            return;
        }

        if(children.size() >= 3)
        {
            dp[u] = h1 + 1;
            ans = max(ans, dp[u]);
            ans = max(ans, h1 + h2 + 1);
        }
        else if (children.size() == 2)
        {
            dp[u] = 1;
            ans = max(ans, dp[u]);
            ans = max(ans, h1 + 1);
        }
        else if (children.size() == 1)
        {
            ans = max(ans, 1ll);
        }
    };

    calc(calc, 0);

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
