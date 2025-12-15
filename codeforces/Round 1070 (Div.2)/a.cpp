#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int ans = 0;
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (v[i] < v[j])
            {
                ans++;
                break;
            }
        }
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
