#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> a;
    bool odd = false, even = false;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if (x & 1) odd = true;
        else even = true;

        a.push_back(x);
    }

    if (odd and even)
    {
        sort(a.begin(), a.end());
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';

    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    while (t--) solve();

    return 0;
}
