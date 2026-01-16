#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int total = 0;
    for(int i = 0; i < n-1; i++)
        total += abs(v[i+1] - v[i]);

    int ans = total - abs(v[0] - v[1]);

    for(int i = 1; i < n; i++)
    {
        int sum = total;

        if(i == n-1)
        {
            sum = total - abs(v[n-1] - v[n-2]);
            if(ans == -1 or sum < ans)
                ans = sum;
            continue;
        }

        sum -= abs(v[i] - v[i-1]);
        sum -= abs(v[i] - v[i+1]);
        sum += abs(v[i+1] - v[i-1]);

        if(ans == -1 or sum < ans)
            ans = sum;
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
