#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v)
    {
        cin >> x;
        x--;
    }

    vector<int> diff(n);
    for(int j = 0; j < n; j++)
        diff[j] = j - v[j];

    vector<int> prefix_max(n);
    prefix_max[0] = diff[0];
    for(int j = 1; j < n; j++)
        prefix_max[j] = max(prefix_max[j-1], diff[j]);

    vector<int> sum(n);
    for(int j = 0; j < n; j++)
        sum[j] = j + v[j];

    vector<int> suffix_min(n);
    suffix_min[n-1] = sum[n-1];
    for(int j = n-2; j >= 0; j--)
        suffix_min[j] = min(suffix_min[j+1], sum[j]);

    // for(int x : prefix_max) cout << x << ' ';
    // cout << '\n';
    // for(int x : suffix_min) cout << x << ' ';
    // cout << '\n';

    int ans = 0;

    for(int j = 0; j < n; j++)
    {
        if(j == 0)
        {
            int dist = v[j] - (suffix_min[j+1] - j);
            ans += max(0ll, dist);
            continue;
        }

        if(j == n-1)
        {
            int dist = v[j] - (j - prefix_max[j-1]);
            ans += max(0ll, dist);
            continue;
        }

        int dist = v[j] - (suffix_min[j+1] - j);
        dist = max(dist, v[j] - (j - prefix_max[j-1]));
        ans += max(0ll, dist);
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
