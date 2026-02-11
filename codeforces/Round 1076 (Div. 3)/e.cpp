#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n; cin >> n;
    map<int, bool> mp;
    vector<int> dp(n+1);
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x == 1)
        {
            dp[1] = 1;
            continue;
        }
        mp[x] = true;
    }

    vector<int> coins;
    for(auto [c, _] : mp) coins.push_back(c);

    for(int i = 2; i <= n; i++)
    {
        if(mp[i])
        {
            dp[i] = 1;
        }

        if(dp[i] == 0)
            continue;

        int limit = n/i;

        for(int j = 0; j < coins.size() and coins[j] <= limit; j++)
        {
            int reach = i * coins[j];

            if(dp[reach] == 0 or dp[i] + 1 < dp[reach])
                dp[reach] = 1 + dp[i];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << (dp[i] ? dp[i] : -1) << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
