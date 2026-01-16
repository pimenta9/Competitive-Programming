#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    map<int, bool> vis;
    vector<int> ans;

    for(int i = n; i >= 1; i--)
    {
        int mask = (1 << i) - 1;
        // cout << mask << '\n';
        for(int j = 0; j < (1 << n); j++)
        {
            if((mask & j) == mask and !vis[j])
            {
                ans.push_back(j);
                vis[j] = true;
            }
        }
    }

    for(int i = 0; i < (1 << n); i++)
    {
        if(!vis[i])
        {
            ans.push_back(i);
            vis[i] = true;
        }
    }

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
