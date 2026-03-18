#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n); for(int& x : v) cin >> x;

    int ans = 0;

    int maior = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] >= maior)
        {
            maior = v[i];
            ans++;
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
