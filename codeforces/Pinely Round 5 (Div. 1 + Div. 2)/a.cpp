#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int r, x, d, n;
    cin >> r >> x >> d >> n;
    string s; cin >> s;

    int ans = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            ans++;
            r = max(0LL, r - d);
        }
        else
        {
            if (r < x)
            {
                ans++;
                r = max(0LL, r - d);
            }
        }
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
