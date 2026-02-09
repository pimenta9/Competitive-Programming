#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, w;
    cin >> n >> w;

    cout << (n/w) * (w-1) + n%w << '\n';
}

int32_t main ()
{
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
