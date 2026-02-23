#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    vector<int> link(n);
    for(int i = 0; i < n; i++)
        link[i] = i;

    for(int i = n-1; i >= 0; i--)
    {
        int x = v[i];

        while(link[i] + 1 < n and v[link[i] + 1] == x+1)
        {
            link[i] = link[link[i] + 1];
        }
    }

    // for(int x : link)
    //     cout << x << ' ';
    // cout << '\n';

    vector<int> dp(n);
    dp[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
    {
        dp[i] = link[i]+1 < n ? dp[link[i]+1] : 0;
        int sz = n - (link[i]+1);
        dp[i] += sz;
        dp[i] += (link[i] - i + 1);
    }

    int ans = 0;
    for(int x : dp) 
    {
        // cout << x << ' ';
        ans += x;
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
