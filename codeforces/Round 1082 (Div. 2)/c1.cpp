#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    vector<int> link(n);
    for(int i = 0; i < n; i++)
        link[i] = i;

    for(int i = n-1; i >= 0; i--)
    {
        int x = v[i];

        while(link[i] + 1 < n and v[link[i] + 1] == x+1)
        {
            link[i] = link[link[i] + 1];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i = link[i] + 1)
    {
        ans++;
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
