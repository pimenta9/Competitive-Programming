#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, x, y;
    cin >> n >> x >> y;

    int quant_blocks = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        quant_blocks += v[i]/x;
    }

    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        int cur = v[i];

        int blocks_left = quant_blocks - v[i]/x;
        cur += y * blocks_left;

        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int32_t main ()
{
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
