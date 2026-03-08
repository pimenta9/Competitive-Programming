#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    vector<int> freq(n+1);

    vector<int> a(n);
    for(int& x : a)
    {
        cin >> x;
        freq[x]++;
    }
    vector<int> b(n);
    for(int& x : b)
    {
        cin >> x;
        freq[x]++;
    }

    for(int i = 1; i <= n; i++)
        if(freq[i] & 1)
        {
            cout << "-1\n";
            return;
        }

    vector<bool> used(n), val(n);
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < n; i++)
    {
        int u = a[i], v = b[i];
        if(u == v)
        {
            adj[u].emplace_back(v, i);
            continue;
        }
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    auto dfs = [&](const auto& rc, const int& u) -> void
    {
        while(!adj[u].empty())
        {
            auto [v, i] = adj[u].back();

            if(used[i])
            {
                adj[u].pop_back();
                continue;
            }

            used[i] = true;
            val[i] = u < v ? 0 : 1;
            rc(rc, v);
        }
    };

    for(int u = 1; u <= n; u++)
    {
        dfs(dfs, u);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if((val[i] == 0 and a[i] > b[i]) or (val[i] == 1 and a[i] < b[i]))
            ans.push_back(i + 1);
    }

    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
