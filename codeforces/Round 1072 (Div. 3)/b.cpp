#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int s, k, m;
    cin >> s >> k >> m;

    if(k < s)
    {
        if((m / k) % 2 == 0)
            cout << s - (m % k) << '\n';
        else
            cout << k - (m % k) << '\n';

        return;
    }

    if(k == s)
    {
        cout << s - (m % k) << '\n';
        return;
    }

    if(k > s)
    {
        cout << max(0ll, s - (m % k)) << '\n';
        return;
    }

    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
