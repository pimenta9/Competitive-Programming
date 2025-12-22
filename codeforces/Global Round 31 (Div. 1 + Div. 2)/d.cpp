#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    int x; cin >> x;

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    vector<int> d(n-1);

    for(int i = 0; i < n-1; i++)
    {
        int y; cin >> y;

        d[i] = y - x;

        x = y;
    }

    // for(int x : d) cout << x << ' ';
    // cout << '\n';

    int ans = 0;
    for(int i = 0, j; i < n-1; i = j)
    {
        // cout << i << '\n';
        // cout << i << '\n';
        int l = 0, r = d[i], L = 0, R = d[i];
        // cout << l << ' ' << r << "\n";
        for(j = i; j < n-1; )
        {
            if(j+1 == n-1)
            {
                j++;
                break;
            }

            if((j-i) & 1)
            {
                R += d[j+1] - d[j];
                r = min(R, r);
            }
            else
            {
                L += d[j] - d[j+1];
                l = max(L, l);
            }

            // cout << j << ' ' << l << ' ' << r << '\n';
            // cout << j << ' ' << l << ' ' << r << '\n';
            if(l < r) j++;
            else break;
        }

        ans += j-i;
        j++;
    }

    cout << ans << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
