#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;

    vector<int> q(n), r(n);
    for(int& x : q) cin >> x;
    for(int& x : r) cin >> x;
    sort(q.begin(), q.end());
    sort(r.rbegin(), r.rend());

    int ans = 0;
    int idx_q = 0;
    for(int i = 0; i < n; i++)
    {
        int remainder = r[i];
        int y = remainder + 1;

        for( ; idx_q < n; )
        {
            if(y * q[idx_q] + remainder <= k)
            {
                ans++;
                idx_q++;
                break;
            }
            else break;
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
