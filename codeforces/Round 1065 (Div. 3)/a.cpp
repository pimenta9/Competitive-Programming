#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    if (n & 1)
    {
        cout << "0\n";
        return;
    }

    cout << n/4 + 1 << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
