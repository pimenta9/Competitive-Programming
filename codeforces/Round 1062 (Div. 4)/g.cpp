#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        v[i] = {a, i};
    }

    sort(v.begin(), v.end());

    vector<int> c(n);
    int ans = 0;
    for (int& x : c)
    {
        cin >> x;
        ans += x;
    }

    vector<int> dp(n, 0);

    int max = -1;
    for (auto [a, i] : v)
    {
        int aux = 0;
        for (int j = 0; j < i; j++)
            if (dp[j] > aux) aux = dp[j];

        dp[i] = aux + c[i];
        if (max == -1 or dp[i] > max) max = dp[i];
    }

    // cout << ans << ' ' << max << '\n';
    ans = ans - max;
    cout << ans << '\n';

    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while (t--) solve();

    return 0;
}
