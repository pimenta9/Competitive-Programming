#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, h;
    cin >> n >> h;

    int up = h, low = h;

    vector<array<int, 3>> queries;
    for (int i = 0; i < n; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;

        queries.push_back({t, l, r});
    }

    int prev_t = 0;
    for (int i = 0; i < n; i++)
    {
        auto [t, l, r] = queries[i];

        int diff = t - prev_t;

        up += diff, low = max(0ll, low-diff);

        if (l > up or r < low)
        {
            cout << "No\n";
            return;
        }

        up = min(up, r);
        low = max(low, l);

        prev_t = t;
    }

    cout << "Yes\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}