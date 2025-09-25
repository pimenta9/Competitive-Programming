#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf 1'000'000'001

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> d(n+1, inf);
    d[0] = -inf;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = v[i];

        int idx = lower_bound(d.begin(), d.end(), x) - d.begin();

        ans = max(ans, idx);

        if (d[idx] == x) continue;

        d[idx] = x;
    }

    cout << ans << '\n';

    return 0;
}