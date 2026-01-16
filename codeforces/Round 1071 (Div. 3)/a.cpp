#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    for(int& x : c) cin >> x;

    vector<int> ij(n), jk(n);
    int ij_sz = 0, jk_sz = 0;
    int ans = n*n*n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(b[(i + j) % n] <= a[i] and !ij[j])
            {
                ij[j] = 1;
                ij_sz++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(c[(i + j) % n] <= b[i] and !jk[j])
            {
                jk[j] = 1;
                jk_sz++;
            }
        }
    }

    // cout << ans << ' ' << ij.size() << ' ' << jk.size() << '\n';

    ans -= ij_sz*n*n;
    ans -= jk_sz*n*(n-ij_sz);

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
