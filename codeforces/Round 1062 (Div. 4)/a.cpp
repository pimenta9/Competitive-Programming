#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == b and b == c and c == d)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
}

int32_t main ()
{
    int t; cin >> t;

    while (t--) solve();

    return 0;
}
