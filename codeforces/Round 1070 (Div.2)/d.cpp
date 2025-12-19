#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998'244'353;

void solve ()
{
    int n, m;
    cin >> n >> m;

    vector<int> val(n);
    for(int& a : val) cin >> a;

    vector<map<int, vector<int>>> adj(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;

        adj[u][val[v]].push_back(v);
    }

    vector<map<int, int>> dp(n);

    auto dfs = [&](auto rc, int node, int target) -> void
    {
        if(dp[node][target] != 0) return;

        int ans = 1;
        for(int v : adj[node][target])
        {
            rc(rc, v, target + val[node]);
            ans = (ans + dp[v][target + val[node]]) % mod;
        }

        dp[node][target] = ans;
    };

    int ans = 0;
    for(int u = 0; u < n; u++)
    {
        for(auto [k, vec] : adj[u])
        {
            for(int v : vec)
            {
                dfs(dfs, v, val[u] + k);
                ans = (ans + dp[v][val[u] + k]) % mod;
            }
        }
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
