#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, a;
    cin >> n >> a;

    vector<int> v(n);
    for (int& x : v) cin >> x;

    int idx = upper_bound(v.begin(), v.end(), a) - v.begin();
    int idx2 = lower_bound(v.begin(), v.end(), a) - v.begin() - 1;

    if ((n - idx) > (idx2 + 1))
        cout << a + 1 << '\n';
    else
        cout << a - 1 << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
