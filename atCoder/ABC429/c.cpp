#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        m[x]++;
    }

    int ans = 0;
    for (auto [x, k] : m)
    {
        if (k < 2) continue;

        ans += (n - k) * ((k*(k-1))/2);
    }

    cout << ans << '\n';

    return 0;
}
