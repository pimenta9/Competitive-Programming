#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve_for_even_k (const vector<int>& v)
{
    int n = size(v);

    int ans = v[0], cur = v[0];
    for (int i = 1; i < n; i++)
    {
        if(cur < 0)
        {
            cur = v[i];
        }
        else
        {
            cur += v[i];
        }

        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

void solve ()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;

    if (k % 2 == 0)
    {
        solve_for_even_k(a);
        return;
    }

    vector<int> psum(n + 1);
    partial_sum(a.begin(), a.end(), psum.begin() + 1);

    vector<int> prefix_min(n+1, psum[0]), suffix_max(n+1, psum[n]);
    for(int i = 1; i <= n; i++) prefix_min[i] = min(prefix_min[i-1], psum[i]);
    for(int i = n-1; i >= 0; i--) suffix_max[i] = max(suffix_max[i+1], psum[i]);

    // for(int x : prefix_min) cout << x << ' ';
    // cout << '\n';
    // for(int x : suffix_max) cout << x << ' ';
    // cout << '\n';

    int ans = b[0] + suffix_max[1] - prefix_min[0];
    for (int i = 2; i <= n; i++)
    {
        int cur = b[i-1] + suffix_max[i] - prefix_min[i-1];
        ans = max(ans, cur);
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
