#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int ans = 0, cap;
    for(int k = 1; k*k <= n; k++)
    {
        for(int r = 0; r < n; r++)
        {
            int x = v[r];

            int l = r - x * k;

            if(l < 0) continue;

            if(v[l] == k) ans++;
        }

        cap = k+1;
    }

    for(int i = 0; i < n; i++)
    {
        int k = v[i];
        if(k < cap) continue;

        int aux = 1;
        for(int j = i + k; j < n; j += k)
        {
            if(v[j] == aux) ans++;
            aux++;
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
