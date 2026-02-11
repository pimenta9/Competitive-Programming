#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int p, q;
    cin >> p >> q;

    if(q <= p)
    {
        cout << "Alice\n";
        return;
    }

    int dist = q-p;

    if(p - 2*dist < 0)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
