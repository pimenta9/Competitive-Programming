#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n, m, d;
    cin >> n >> m >> d;

    int max_size = d/m + 1;

    int ans = (n+max_size-1) / max_size;
    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
