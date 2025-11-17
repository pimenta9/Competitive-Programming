#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    int ans = -1;
    for (int l = 1, r = 1e12; l <= r; )
    {
        int mid = (l + r)/2;
        int p = mid;

        for (int i = 0; i < x; i++)
        {
            p -= p/y;
        }

        if (p > k) r = mid-1;
        if (p == k)
        {
            ans = mid;
            r = mid-1;
        }
        if (p < k)
        {
            l = mid+1;
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
