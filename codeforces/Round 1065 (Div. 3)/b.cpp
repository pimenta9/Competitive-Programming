#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;

    int x;
    if (v[0] == -1 and v[n-1] != -1) v[0] = v[n-1];
    if (v[0] != -1 and v[n-1] == -1) v[n-1] = v[0];

    for (int& y : v)
    {
        if (y == -1) y = 0;
    }

    cout << abs(v[n-1] - v[0]) << '\n';
    for (int y : v) cout << y << ' ';
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
