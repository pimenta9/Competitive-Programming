#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int& x : a) { cin >> x; sum += x; }

    vector<int> v(n);
    v[0] = max(0LL, 2 - a[0]);

    for (int i = 1; i < n; i++)
    {
        v[i] = max(0LL, v[i-1] + 2*(i-1+1) + 2 - a[i]);
    }

    // for (int i = 0; i < n; i++) cout << v[i] << ' ';
    // cout << '\n';

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (ans == -1 or v[i] > ans) ans = v[i];
    }

    cout << ans + sum << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
