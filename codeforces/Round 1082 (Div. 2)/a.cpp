#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int x, y;
    cin >> x >> y;

    int X = 0, Y = 0;
    if(y < 0)
    {
        X = 4*abs(y);
        Y = y;

        if(x - X >= 0 and (x-X)%3==0)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }

    Y = y;
    X = 2*abs(y);

    if(x - X >= 0 and (x-X)%3==0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
