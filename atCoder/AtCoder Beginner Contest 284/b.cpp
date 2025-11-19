#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;

    int ans = 0;

    while (n--)
    {
        int x; cin >> x;
        if (x & 1) ans++;
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
