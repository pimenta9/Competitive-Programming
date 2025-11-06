#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;

    vector<int> freq(n+1, 0);

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;

        freq[x]++;
    }

    vector<int> psum(n+1);
    psum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        psum[i] = freq[i] + psum[i-1];
    }

    // for (int i = 0; i <= n; i++)
    //     cout << i << ": " << freq[i] << '\n';
    // cout << "---------\n";
    // for (int i = 0; i <= n; i++)
    //     cout << psum[i] << '\n';

    int ans;

    for (int i = 1; i <= n; i++)
    {
        int goods = 0;

        goods += freq[i];
        if (2*i <= n)
            goods += freq[2*i];
        if (3*i <= n)
            goods += freq[3*i];

        if (4*i <= n)
            goods += psum[n] - psum[4*i - 1];

        if (goods >= n - k)
            ans = i;
    }

    cout << ans << '\n';
    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
