#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int l, a, b;
    cin >> l >> a >> b;

    vector<bool> vis(l);

    int ans = a;
    while(true)
    {
        vis[a] = true;
        ans = max(ans, a);

        a = (a + b) % l;
        if(vis[a]) break;
    }

    cout << ans << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
