#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, k, V;
    cin >> n >> k >> V;
    V--;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n), seen(n);

    auto dfs = [&](auto rc, int u) -> void
    {
        seen[u] = true;

        vector<int> children;
        for(int v : adj[u])
            if(!seen[v]) children.push_back(v);

        if(children.size() == 0)
            return;

        for(int v : children)
            rc(rc, v);

        int first_min = -1, second_min = -1;
        for(int v : children)
        {
            if(first_min == -1 or dp[v] < first_min)
            {
                swap(first_min, second_min);
                first_min = dp[v];
            }
            else if (second_min == -1 or dp[v] < second_min)
                second_min = dp[v];
        }

        if(second_min == -1)
            dp[u] = first_min + 1;
        else
            if(first_min + second_min + 2 <= k+1)
                dp[u] = 0;
            else dp[u] = first_min + 1;
    };

    dfs(dfs, V);

    // for(int x : dp) cout << x << ' ';
    // cout << '\n';

    cout << (dp[V] == 0 ? "YES\n" : "NO\n");
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
