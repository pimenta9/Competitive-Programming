#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    map<int, vector<pair<int, int>>> mp;
    for(int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;

        mp[l].push_back({0, i});
        mp[r+1].push_back({1, i});
    }

    map<int, bool> seen, vis;
    for(auto [_, v] : mp)
    {
        for(auto [action, idx] : v)
        {
            if(action == 0)
                seen[idx] = true;
            else
                seen.erase(idx);
        }

        if(seen.empty())
            continue;

        vis[seen.rbegin()->first] = true;
    }

    cout << vis.size() << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
