#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v)
    {
        cin >> x;
    }

    if(v[0] == 1 or v[n-1] == 1)
    {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
